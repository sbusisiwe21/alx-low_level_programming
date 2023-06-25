#include <stdio.h>

// Function to calculate the length of a list
int listLength(int* list) {
    int length = 0;
    while (*list != 0) {
        length++;
        list++;
    }
    return length;
}

int main() {
    int myList[] = {1, 2, 3, 4, 5, 0};  // Example list with 5 elements
    int length = listLength(myList);
    
    printf("Length of the list: %d\n", length);
    
    return 0;
}

