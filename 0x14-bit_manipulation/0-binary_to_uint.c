#include "main.h"
#include "stddef.h"
/**
 * binary_to_uint - Convert binary number into unsigned int
 * @b: pointer to 0 and 1
 * Return: unsigned int
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int number = 0;

	if (b == NULL)
	{
	return (0);
	}

	for (; *b != '\0'; b++)
	{
		if (*b == '0')
		{
			number = number << 1;
		}
		else if (*b == '1')
		{
			number = (number << 1) | 1;
		}
		else
		return (0);
	}
	return (number);
}
