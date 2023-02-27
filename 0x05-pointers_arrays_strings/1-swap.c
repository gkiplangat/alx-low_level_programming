#include "main.h"

/**
 * swap_int -swaps the value of the pointer it points to
 * @a:-first value
 * @b:-second value
 * Return:Always 0
 */

void swap_int(int *a, int *b)
{

	*a += *b;
	*b = *a - *b;
	*a = *a - *b;
}
