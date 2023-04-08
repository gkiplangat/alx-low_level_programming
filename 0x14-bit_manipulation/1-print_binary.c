#include "main.h"
#include <stdio.h>

/**
* print_binary - prints binary representation of a number
* @n: - the number
* Return:void
*/

void print_binary(unsigned long int n)
{
	int bits = sizeof(unsigned long int) * 8 - 1;
	int printed = 0;

	while (bits >= 0)
	{
	unsigned long int mask = 1ul << bits;

	if ((n & mask) == mask)
	{
	putchar('1');
	printed = 1;
	}
	else if (printed)
	{
	putchar('0');
	}
	bits--;
	}
	if (!printed)
	{
	putchar('0');
	}
}
