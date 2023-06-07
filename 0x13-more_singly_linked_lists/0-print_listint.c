#include "lists.h"

/**
 * print-listint - prints all the elements of a linked list
 * @h: linked lis of type listint_t to traverse
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}

	return (num);
}
