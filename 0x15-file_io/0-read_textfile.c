#include <stdio.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	FILE *file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	char buffer[letters + 1];  /* +1 for null terminator */
	ssize_t numRead = fread(buffer, sizeof(char), letters, file);
	if (numRead < 0)
	{
		fclose(file);
		return (0);
	}

	buffer[numRead] = '\0';  /* Null-terminate the string */

	if (ferror(file) != 0 || numRead != fwrite(buffer, sizeof(char), numRead, stdout))
	{
		fclose(file);
		return (0);
	}

	fclose(file);
	return (numRead);
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	const char *filename = "example.txt";
	size_t letters_to_read = 100;

	ssize_t numLettersRead = read_textfile(filename, letters_to_read);
	if (numLettersRead == 0)
	{
		printf("Failed to read the file.\n");
	}
	else
	{
		printf("Number of letters read and printed: %zd\n", numLettersRead);
	}

	return (0);
}
