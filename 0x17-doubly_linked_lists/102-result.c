#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int num);

/**
 * main - prints the largest palindrome made from the product of
 *		  two 3-digit numbers and saves it to a file.
 *
 * Return: Largest palindrome number.
 */

int main(void)
{
	int largest3d_Palindrome = 0;
	int x, y;
	FILE *f_pointer;
	char *fname = "./102-result";

	for (x = 999; x >= 100; x--)
		for (y = 999; y >= 100; y--)
		{
			int product = x * y;

			if (product > largest3d_Palindrome && isPalindrome(product))
				largest3d_Palindrome = product;
		}

	printf("The largest palindrome made from the product");
	printf(" of two 3-digit numbers is: %d\n", largest3d_Palindrome);

	fptr = fopen(fname, "w");
	if (!f_pointer)
	{
		perror("Error!");
		exit(EXIT_FAILURE);
	}

	fprintf(f_pointer, "%d", largest3d_Palindrome);
	fclose(f_pointer);

	printf("It's been saved to the file %s in current directory.\n", fname);

	return (0);
}

/**
 * isPalindrome - checks if a number is a palindrome
 * @num: Number to be checked.
 *
 * Return: Largest number.
 */

int isPalindrome(int num)
{
	int reversedNumber = 0;
	int temp = num;

	while (temp != 0)
	{
		reversedNumber = reversedNumber * 10 + temp % 10;
		temp /= 10;
	}

	return (num == reversedNumber);
}
