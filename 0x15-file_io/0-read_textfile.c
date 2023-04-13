#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - read a text file and print output in POSIX standard output
 * @filename: - file to be read
 * @letters: - number of letters it should read and print
 * Return: 1 on success else 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t openf, readf, writef;
	char *buffer;

	if (filename == NULL)
	return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	return (0);

	openf = open(filename, O_RDONLY);
	readf = read(openf, buffer, letters);
	writef = write(STDOUT_FILENO, buffer, readf);

	if (openf == -1 || readf == -1 || writef == -1 || writef != readf)
	{
	free(buffer);
	return (0);
	}
	free(buffer);
	close(openf);
	return (writef);
}

