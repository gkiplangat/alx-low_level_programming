#include "main.h"
#include <stdio.h>

/**
 * get_endianness -check the endianness
 * Return: 0 if big endian and 1 if little endian
 */

int get_endianness(void)
{
	int n = 1;
	char *ptr = (char *)&n;

	if (ptr[0] == 1)
	{
	return (1);
	}
	else
	{
	return (0);
	}
}
