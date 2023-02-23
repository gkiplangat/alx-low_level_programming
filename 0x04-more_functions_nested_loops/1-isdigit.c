#include "main.h"

/**
 * main -Entry point
 * _isdigit tests an integer value.
 * Return : 1 for digitotherwise 0
 */

int _isdigit(int c)

{
if (c >= 48 && c <= 57)
{
return (1);
}
return (0);
}
