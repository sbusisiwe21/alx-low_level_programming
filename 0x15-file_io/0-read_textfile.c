#include <stdio.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 *         0 if the file cannot be opened or read, or if filename is NULL.
 *         0 if write fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	FILE *file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	char buffer[letters + 1];
	ssize_t bytesRead = fread(buffer, sizeof(char), letters, file);

	if (bytesRead == 0)
	{
		fclose(file);
		return (0);
	}

	buffer[bytesRead] = '\0';
	printf("%s", buffer);

	fclose(file);
	return (bytesRead);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	const char *filename = "example.txt";
	size_t letters = 100;

	ssize_t bytesRead = read_textfile(filename, letters);
	printf("Read %ld letters from the file.\n", bytesRead);

	return (0);
}
