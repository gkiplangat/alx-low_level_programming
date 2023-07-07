#include "hash_tables.h"

void insert_node_at_beginning(hash_node_t **head, hash_node_t *node);

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table to add the key-value pair to.
 * @key: The key to be hashed and placed on the array.
 * @value: The value to be assigned to that key.
 *
 * Return: 1 if success or 0 if failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *hash_table_pair, *hash_table_curr, **hash_table_bucket;
	unsigned long int index;
	char *value_dup;

	if (!ht || !key || !(*key) || !value)
		return (0);

	/* Get the index for the key and the address of the bucket */
	index = key_index((unsigned char *)key, ht->size);
	hash_table_bucket = &(ht->array[index]);
	hash_table_curr = ht->array[index];

	/* Make a copy of the value string */
	value_dup = strdup(value);
	if (value_dup == NULL)
		return (0);

	/* If the key exists then just update the value */
	while (hash_table_curr)
	{
		if (strcmp(hash_table_curr->key, key) == 0)
		{
			free(hash_table_curr->value);
			hash_table_curr->value = value_dup;
			return (1);
		}
		hash_table_curr = hash_table_curr->next;
	}

	/* Allocate memory for the new key-value pair and handle errors */
	hash_table_pair = malloc(sizeof(hash_node_t));
	if (hash_table_pair == NULL)
	{
		free(value_dup);
		return (0);
	}

	hash_table_pair->key = strdup(key);
	if (hash_table_pair->key == NULL)
	{
		free(value_dup);
		free(hash_table_pair);
		return (0);
	}

	hash_table_pair->value = value_dup;
	hash_table_pair->next = NULL;

	/* If the index is not taken, then place the new key-value pair there. */
	if (*hash_table_bucket == NULL)
	{
		*hash_table_bucket = hash_table_pair;
		return (1);
	}

	/* If code gets here then there is a collision. Add new node at start. */
	if (*hash_table_bucket && strcmp((*hash_table_bucket)->key, key) != 0)
		insert_node_at_beginning(&(*hash_table_bucket), hash_table_pair);

	return (1);
}

/**
 * insert_node_at_beginning - Adds a new node at the start of the linked list.
 * @head: The first node of the singly-linked list.
 * @node: The new node to add (represents the key-value pair).
 *
 * Return: Nothing.
 */
void insert_node_at_beginning(hash_node_t **head, hash_node_t *node)
{
	if (*head == NULL)
		*head = node;

	node->next = *head;
	*head = node;
}
