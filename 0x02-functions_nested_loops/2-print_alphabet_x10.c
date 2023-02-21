#include "main.h"

/**
 * print alphabet -Make the alphabet
 *
 * Return: void
 */

void print_alphabet_x10(void)
{

char ch;
int i;

for(ch = 'a'; ch <= 'z'; ch++)
for (i =0; i < 10; i++)
_putchar(ch);
_putchar('\n');


}
