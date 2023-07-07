#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the hash table.
 *
 * Return: Pointer to the new table, or NULL on failure
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shash_table;
	unsigned long int i;

	/* Allocate memory for the hash table structure */
	shash_table = malloc(sizeof(shash_table_t));
	if (shash_table == NULL)
		return (NULL);
	shash_table->size = size;
	shash_table->shead = NULL;
	shash_table->stail = NULL;

	/* Allocate memory for the array of hash nodes */
	shash_table->array = malloc(sizeof(shash_node_t *) * size);
	if (shash_table->array == NULL)
	{
		free(shash_table);
		return (NULL);
	}

	/* Initialize the array with NULL pointers */
	for (i = 0; i < size; i++)
		shash_table->array[i] = NULL;

	return (shash_table);
}

/**
 * make_shash_node - Creates a node for the sorted hash table.
 * @key: Key for the data.
 * @value: Value assiciated with the key.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */

shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *shn;

	/* Allocate memory for the new hash node */
	shn = malloc(sizeof(shash_node_t));
	if (shn == NULL)
		return (NULL);

	/* Duplicate and store the key */
	shn->key = strdup(key);
	if (shn->key == NULL)
	{
		free(shn);
		return (NULL);
	}

	/* Duplicate and store the value */
	shn->value = strdup(value);
	if (shn->value == NULL)
	{
		free(shn->key);
		free(shn);
		return (NULL);
	}

	shn->next = shn->snext = shn->sprev = NULL;
	return (shn);
}

/**
 * add_to_sorted_list - Adds a node to the linked list (sorted by key's ASCII)
 * @table: The sorted hash table.
 * @node: The node to add.
 *
 * Return: void
 */

void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *sht_curr;

	/* If the sorted list is empty, make the node the head and tail */
	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}

	sht_curr = table->shead;
	while (sht_curr != NULL)
	{
		/* Insert the node at the correct position based on key's ASCII order */
		if (strcmp(node->key, sht_curr->key) < 0)
		{
			node->snext = sht_curr;
			node->sprev = sht_curr->sprev;
			sht_curr->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		sht_curr = sht_curr->snext;
	}

	/* If the node has the highest key, make it the new tail */
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - Assigns a value to a key in the hash table.
 * @ht: The sorted hash table
 * @key: Key to assign
 * @value: Data to add
 *
 * Return: 1 on success, 0 otherwise
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *new_value;
	shash_node_t *shn, *sht_curr;

	/* Check for invalid input or empty hash table */
	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
		key == NULL || strlen(key) == 0 || value == NULL)
		return (0);

	/* Get the index for the key */
	index = key_index((const unsigned char *)key, ht->size);
	sht_curr = ht->array[index];

	/* Update the value if the key already exists */
	while (sht_curr != NULL)
	{
		if (strcmp(sht_curr->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(sht_curr->value);
			sht_curr->value = new_value;
			return (1);
		}
		sht_curr = sht_curr->next;
	}

	/* Create a new hash node and add it to the array and sorted list */
	shn = make_shash_node(key, value);
	if (shn == NULL)
		return (0);
	shn->next = ht->array[index];
	ht->array[index] = shn;
	add_to_sorted_list(ht, shn);
	return (1);
}

/**
 * shash_table_get - Retrieves a value from the hash table.
 * @ht: Hash table.
 * @key: Key to the data.
 *
 * Return: The value associated with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *sht_curr;

	/* Check for invalid input or empty hash table */
	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
		key == NULL || strlen(key) == 0)
		return (NULL);

	/* Get the index for the key */
	index = key_index((const unsigned char *)key, ht->size);
	sht_curr = ht->array[index];

	/* Search for the key in the linked list */
	while (sht_curr != NULL)
	{
		if (strcmp(sht_curr->key, key) == 0)
			return (sht_curr->value);
		sht_curr = sht_curr->next;
	}
	return (NULL);
}


/**
 * shash_table_print - Prints a sorted hash table (doubly-linked list)
 * @ht: Hash table to be printed
 *
 * Return: Nothing.
 */
void shash_table_print(const shash_table_t *ht)
{
		shash_node_t *sht_curr;
		char first_printed = 0;

		if (ht == NULL || ht->array == NULL)
			return;

		putchar('{');

		sht_curr = ht->shead;
		while (sht_curr != NULL)
		{
			if (first_printed == 1)
				printf(", ");
			printf("'%s': '%s'", sht_curr->key, sht_curr->value);
			first_printed = 1;
			sht_curr = sht_curr->snext;
		}

		printf("}\n");
}


/**
 * shash_table_print_rev - Prints a sorted hash table (doubly-linked list)
 *												   in reverse order.
 * @ht: Hash table to be printed
 *
 * Return: Nothing.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
		shash_node_t *sht_curr;
		char first_printed = 0;

		if (ht == NULL || ht->array == NULL)
			return;

		putchar('{');

		sht_curr = ht->stail;
		while (sht_curr != NULL)
		{
			if (first_printed == 1)
				printf(", ");
			printf("'%s': '%s'", sht_curr->key, sht_curr->value);
			first_printed = 1;
			sht_curr = sht_curr->sprev;
		}

		printf("}\n");
}


/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: Hash table to delete.
 *
 * Return: Nothing
 */
void shash_table_delete(shash_table_t *ht)
{
		unsigned long int n;
		shash_node_t *next;

		if (ht == NULL || ht->array == NULL || ht->size == 0)
			return;

		for (n = 0; n < ht->size; ++n)
		{
			while (ht->array[n])
			{
				next = ht->array[n]->next;
				free(ht->array[n]->key);
				free(ht->array[n]->value);
				free(ht->array[n]);
				ht->array[n] = next;
			}
		}
		free(ht->array);
		ht->array = NULL;
		ht->shead = ht->stail = NULL;
		ht->size = 0;
		free(ht);
}
