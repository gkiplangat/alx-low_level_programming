#include "main.h"
#include <stdio.h>

/**
* print_binary - prints binary representation of a number
* @n: - the number
* Return:void
*/

void print_binary(unsigned long int n)
{
	int a;

	for (a = (sizeof(unsigned long int) * 8) - 1; a >= 0; a--)
	{
	if (n & (1ul << a))
	{
	putchar('1');
	}
	else
	{
	putchar('0');
	}
	}
}

