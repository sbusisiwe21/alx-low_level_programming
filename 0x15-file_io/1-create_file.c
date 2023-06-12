#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"

/**
 * create_file - Create a file with the given filename and write the
 *               text_content to it.
 * @filename: The name of the file to create.
 * @text_content: The text to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	if (filename == NULL)
		return (-1);

	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)


		return (-1);

	if (text_content != NULL)
	{
		ssize_t bytes_written = write(fd, text_content, strlen(text_content));

		if (bytes_written == -1)

		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	const char *filename = "example.txt";
	char *text_content = "This is an example text.";

	int result = create_file(filename, text_content);

	if (result == -1)

	{
		printf("Failed to create the file.\n");
	}
	else
	{
		printf("File created successfully.\n");
	}

	return (0);
}
