#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - read a text file and print output in POSIX standard output
 * @filename: - file to be read
 * @letters: - number of letters it should read and print
 * Return: 1 on success else 0
 */


ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file = fopen(filename, "r");
	char *buffer = (char *) malloc(letters + 1);
	ssize_t bytes_read = fread(buffer, sizeof(char), letters, file);
	ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	if (filename == NULL)
	{
	return (0);
	}

	if (file == NULL)
	{
	return (0);
	}
	if (buffer == NULL)
	{
	fclose(file);
	return (0);
	}
	if (bytes_read < 0)
	{
	fclose(file);
	free(buffer);
	return (0);
	}
	buffer[bytes_read] = '\0';
	if (bytes_written < 0 || bytes_written != bytes_read)
	{
	fclose(file);
	free(buffer);
	return (0);
	}
	fclose(file);
	free(buffer);
	return (bytes_read);
}
