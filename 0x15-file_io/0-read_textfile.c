#include <stdio.h>

int main() {
    FILE *file;
    char ch;

    // Open the file
    file = fopen("myfile.txt", "r");
    
    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    // Read and print the contents of the file character by character
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    
    // Close the file
    fclose(file);
    
    return 0;
}

