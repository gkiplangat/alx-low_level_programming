#include "hash_tables.h"

void insert_node_at_the begining(hash_node_t **head, hash_node_t *node);

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
    hash_node_t *hash_table_p, *ht_curr, **ht_bucket;
    unsigned long int index;
    char *value_dup;

    if (!ht || !key || !(*key) || !value)
        return (0);


    index = key_index((unsigned char *)key, ht->size);
    ht_bucket = &(ht->array[index]);
    ht_curr = ht->array[index];
    /* Make a copy of the value string */
    value_dup = strdup(value);
    if (value_dup == NULL)
        return (0);

    /* If the key exists then just update the value */
    while (ht_curr)
    {
        if (strcmp(ht_curr->key, key) == 0)
        {
            free(ht_curr->value);
            ht_curr->value = value_dup;
            return (1);
        }
        ht_curr = ht_curr->next;
    }

    /* Allocate memory for the new key-value pair and handle errors */
    hash_table_p = malloc(sizeof(hash_node_t));
    if (hash_table_p == NULL)
    {
        free(value_dup);
        return (0);
    }

    hash_table_p->key = strdup(key);
    if (hash_table_p->key == NULL)
    {
        free(value_dup);
        free(hash_table_p);
        return (0);
    }

    hash_table_p->value = value_dup;
    hash_table_p->next = NULL;

    /* If the index is not taken, then place the new key-value pair there. */
    if (*ht_bucket == NULL)
    {
        *ht_bucket = hash_table_p;
        return (1);
    }

    /* If code gets here then there is a collision. Add new node at start. */
    if (*ht_bucket && strcmp((*ht_bucket)->key, key) != 0)
        insert_node_at_the begining(&(*ht_bucket), hash_table_p);

    return (1);
}

/**
 * insert_node_at_the begining - Adds a new node at the start of the linked list.
 * @head: The first node of the singly-linked list.
 * @node: The new node to add (represents the key-value pair).
 *
 * Return: Nothing.
 */
void insert_node_at_the begining(hash_node_t **head, hash_node_t *node)
{
    if (*head == NULL)
        *head = node;

    node->next = *head;
    *head = node;
}
