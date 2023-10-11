#include "search_algos.h"

/**
 * linear_search- search for a value in an array.
 * @array: Integer array to be searched
 * @size: The size of the array
 * @value: The value to search for
 *
 * Return: The first index where the value is located or -1 if not found.
*/

int linear_search(int *array, size_t size, int value)
{
	size_t u;

	if (array == NULL)
		return (-1);

	for (u = 0; u < size; u++)
	{
		printf("Value checked array[%ld] = [%d]\n", u, array[u]);
		if (array[u] == value)
		{
			return (u);
		}
	}

	return (-1);
}
