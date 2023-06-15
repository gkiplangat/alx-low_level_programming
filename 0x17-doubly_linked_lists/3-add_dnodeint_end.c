#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a doubly linked list
 * @head: Pointer to first node in the list.
 * @n: new node data.
 *
 * Return: pointer to the newly added node.
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *nw_node, *curr_n;

	curr_n = *head;
	nw_node = malloc(sizeof(dlistint_t));
	if (!nw_node)
		return (NULL);

	if (curr_n)
		while (curr_n->next)
			curr_n = curr_n->next;

	nw_node->n = n;
	nw_node->next = NULL;
	nw_node->prev = curr_n;

	if (*head == NULL)
		*head = nw_node;
	else
		curr_n->next = nw_node;

	return (nw_node);
}
