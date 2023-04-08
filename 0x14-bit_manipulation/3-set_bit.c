#include "main.h"
#include <stdio.h>

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to the unsigned long int to set bit into
 * @index: index of the bit to set.
 * Return: 1 if it worked else -1
 */

int set_bit(unsigned long int *n, unsigned int index)
{

	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
	return (-1);
	}
	mask = 1ul << index;
	*n = *n | mask;
	return (1);
}

