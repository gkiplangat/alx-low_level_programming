#include "main.h"
#include "stddef.h"

/**
 * binary_to_uint -convert binary number
 * @b:string pointer
 * Return: 0
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int number = 0;

	if (b == NULL)
	return (0);

	for (; *b != '\0'; b++)
	{
	if (*b == '0')
	number = number << 1;
	else if (*b == '1')
	number = (number << 1) | 1;
	else
	return (0);
	}

	return (number);
}

