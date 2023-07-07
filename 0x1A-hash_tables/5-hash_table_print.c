#include "hash_tables.h"

/**
 * hash_table_print - prints the keys and values of the hash table
 *
 * @ht: pointer to the hash table
 * Return: no return
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int x;
	hash_node_t *tmp;
	char *seperator;

	if (ht == NULL)
		return;

	printf("{");
	seperator = "";

	for (x = 0; x < ht->size; x++)
	{
		tmp = ht->array[x];
		while (tmp != NULL)
		{
			printf("%s'%s': '%s'", seperator, tmp->key, tmp->value);
			seperator = ", ";
			tmp = tmp->next;
		}
	}
	printf("}\n");
}
