#include "main.h"

/**
 * print_alphabet_x10 - a function that prints the alphabet
 *
 * Return: Always 0
 */

void print_alphabet_x10(void)
{
char words;
int t = 0;
while (t <= 9)
{
for (words = 'a'; words <= 'z'; words++)
{
_putchar(words);
}
_putchar('\n');
t++;
}
}
