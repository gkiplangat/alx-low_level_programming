#include "lists.h"

/**
 * add_dnodeint - adds new node at the beginning of a doubly linked list
 * @head: Pointer to first node in the list.
 * @n: Data for the new node.
 *
 * Return: pointer newly added node.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *nw_node;

	nw_node = malloc(sizeof(dlistint_t));
	if (!nw_node)
		return (NULL);

	nw_node->n = n;
	nw_node->next = *head;
	nw_node->prev = NULL;

	if (*head)
		(*head)->prev = nw_node;
	*head = nw_node;

	return (nw_node);
}
