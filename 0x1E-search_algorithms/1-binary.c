#include "search_algos.h"

/**
 * binary_search - Binary search algorithm.
 * @array: Integer array to be searched
 * @size: The size of the array
 * @value: The value to search for
 *
 * Return: The index where the value is located or -1 if not found.
*/

int binary_search(int *array, size_t size, int value)
{
	size_t u, left, right, mid;

	if (array == NULL || size == 0)
		return (-1);

	left = 0;
	right = size - 1;

	while (left <= right)
	{
		printf("Searching in array: ");
		for (u = left; u < right; u++)
			printf("%d, ", array[u]);
		printf("%d\n", array[u]);

		mid = left + (right - left) / 2;

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			left = mid + 1;
		right = mid - 1;
	}

	return (-1);
}
