#include <stddef.h> /* for size_t */

/* Linked list node structure */
typedef struct node
{
    int data;
    struct node *next;
} node_t;

/* Linked list structure */
typedef struct list
{
    node_t *head;
} list_t;

/**
 * list_len - Calculate the length of a linked list
 * @h: Pointer to the head of the list
 *
 * Return: The number of elements in the list
 */
size_t list_len(const list_t *h)
{
    size_t count = 0;
    const node_t *current = h->head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}
