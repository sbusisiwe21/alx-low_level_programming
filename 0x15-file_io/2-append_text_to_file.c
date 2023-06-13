#include <stdio.h>
#include "main.h"

int append_text_to_file(const char *filename, char *text_content)
{
	if (filename == NULL)
		return -1; /* Invalid filename */

	if (text_content == NULL)
		return 1; /* Nothing to add to the file */

	FILE *file = fopen(filename, "a"); /* Open the file in append mode */
	if (file == NULL)
		return -1; /* Unable to open the file */

	fputs(text_content, file); /* Write the text_content to the file */
	fclose(file); /* Close the file */

	return 1; /* Success */
}

int main(void)
{
	const char *filename = "example.txt";
	char *text_content = "This is some text to append.";

	int result = append_text_to_file(filename, text_content);
	if (result == 1)
		printf("Text appended to the file successfully.\n");
	else
		printf("Failed to append text to the file.\n");

	return 0;
}

