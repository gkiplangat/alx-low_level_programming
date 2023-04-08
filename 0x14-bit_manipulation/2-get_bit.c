#include <stdio.h>
#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @index: -index of a given bit
 * @n:- unsigned long int to get bit from
 * Return: value of the bit at index or -1 if an error occurred
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
	return (-1);
	}

	mask = 1ul << index;

	if ((n & mask) == mask)
	{
	return (1);
	}
	else
	{
	return (0);
	}
}

