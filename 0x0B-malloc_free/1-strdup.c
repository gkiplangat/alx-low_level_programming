#include "main.h"
#include <stdlib.h>

/**
 * _strdup - copy a string to a newly allocated space in memory
 * @str: string to copy
 *
 * Return: pointer to duplicated string or NULL if error
 */
char *_strdup(char *str)
{
	unsigned int k, m;
	char *s;

	if (str == NULL)
		return (NULL);
	for (k = 0; str[k]; k++)
		;
	k++;
	s = malloc(k * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}
	for (m = 0; m < k; m++)
	{
		s[m] = str[m];
	}
	return (s);
}
