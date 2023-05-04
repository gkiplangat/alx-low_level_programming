#include "main.h"
#include <stdio.h>

/**
 * flip_bits - Returns the number of bits needed to flip to get from one
 *             number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip to get from n to m.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_outcome = n ^ m;
	unsigned int flips = 0;

	while (xor_outcome > 0)
	{
	if ((xor_outcome & 1) == 1)
	flips++;
	xor_outcome >>= 1;
	}
	return (flips);
}


