#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int num);

/**
 * main - prints the largest palindrome made from the product of
 *		  two 3-digit numbers and saves it to a file.
 *
 * Return: Largest number.
 */

int main(void)
{
	int largestPalindrome = 0;
	int i, j;
	FILE *fptr;
	char *filename = "./102-result";

	for (i = 999; i >= 100; i--)
		for (j = 999; j >= 100; j--)
		{
			int product = i * j;

			if (product > largestPalindrome && isPalindrome(product))
				largestPalindrome = product;
		}

	printf("The largest palindrome made from the product");
	printf(" of two 3-digit numbers is: %d\n", largestPalindrome);

	fptr = fopen(filename, "w");
	if (!fptr)
	{
		perror("Error!");
		exit(EXIT_FAILURE);
	}

	fprintf(fptr, "%d", largestPalindrome);
	fclose(fptr);

	printf("It's been saved to the file %s in current directory.\n", filename);

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
	int reversedNum = 0;
	int temp = num;

	while (temp != 0)
	{
		reversedNum = reversedNum * 10 + temp % 10;
		temp /= 10;
	}

	return (num == reversedNum);
}
