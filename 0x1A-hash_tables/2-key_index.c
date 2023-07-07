#include "hash_tables.h"

/**
 * key_index - hash table array index position.
 * @key: The key to be hashed.
 * @size: Size of the hash table array.
 *
 * Return: The index of the key on the hash table array.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hsh, index;

	hsh = hash_djb2(key);
	index = hsh % size;

	return (index);
}
