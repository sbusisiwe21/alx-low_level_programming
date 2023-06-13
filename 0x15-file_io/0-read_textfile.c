#include <stdio.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 *         0 if the file cannot be opened or read, or if filename is NULL,
 *         or if write fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	FILE *file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	char buffer[letters + 1];
	ssize_t read_count = fread(buffer, sizeof(char), letters, file);
	if (read_count < 0)
	{
		fclose(file);
		return (0);
	}

	buffer[read_count] = '\0';
	printf("%s", buffer);

	fclose(file);
	return (read_count);
}

