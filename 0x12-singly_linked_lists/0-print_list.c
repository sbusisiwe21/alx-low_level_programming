#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a linked list.
 * @h: pointer to the list_t list to print
 *
 * Return: Always 0.
 */
size_t print_list(const list_t *h)
{
	size_t z = 0;

	while (k)
	{
		if (!k->str)
			printf("[0](nil)\n");
		else
			printf("[%u] %s\n", k->len, k->str);
		k = k->next;
		z++;
	}

	return (z);
}
