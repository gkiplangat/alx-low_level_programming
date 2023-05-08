#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file to append text to
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file, length = 0, written = 0;

	file = open(filename, O_WRONLY | O_APPEND);

	if (filename == NULL)
	return (-1);
	if (text_content != NULL)
	{
	while (text_content[length])
	length++;
	}
	if (file == -1)
	return (-1);
	if (text_content != NULL)
	written = write(file, text_content, length);
	close(file);
	if (written != length)
	return (-1);
	return (1);
}

