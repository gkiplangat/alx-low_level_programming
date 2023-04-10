#include "main.h"

/**
 * create_file - Creates a file with given text content
 * @filename: The name of the file to create
 * @text_content: A NULL-terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, result = 1, count = 0;

	if (!filename)
	return (-1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
	return (-1);
	if (text_content)
	{
	while (text_content[count])
	count++;
	result = write(fd, text_content, count);
	}
	if (result == -1)
	return (-1);
	close(fd);
	return (1);
}

