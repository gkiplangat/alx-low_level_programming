#include <stdlib.h>
#include "main.h"
#include <stddef.h>

/**
* *array_range - creates an array of integers
* @min: minimum range of values stored
* @max: maximum range of values stored and number of elements
*
* Return: pointer to the new array
*/
int *array_range(int min, int max)
{
   int *ptr;
   int i, size;


   if (min > max)
       return (NULL);


   size = max - min + 1;


   ptr = malloc(sizeof(int) * size);


   if (!ptr)
       return (NULL);


   for (i = 0; i < size; i++)
       ptr[i] = min++;


   return (ptr);
}



