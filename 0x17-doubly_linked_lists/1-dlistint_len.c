#include "lists.h"

/**
 * dlistint_len - returns the length of a doubly linked list
 * @h: Pointer to first node in the list.
 *
 * Return: No of nodes in the list.
 */

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *n = h;
	size_t length = 0;

	while (n)
	{
		length++;
		n = n->next;
	}

	return (length);
}
