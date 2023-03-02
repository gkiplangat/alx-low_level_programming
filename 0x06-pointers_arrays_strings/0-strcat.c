#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 *
 *
 */

char *_strcat(char *dest, char *src)
{

	dest = "Hello ";
	src = "World";
	
	strcat(dest, src);
	printf("strcat(dest,src): %s\n", dest);
	return (0);
}
