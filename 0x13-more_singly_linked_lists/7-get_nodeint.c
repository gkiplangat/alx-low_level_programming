#include "lists.h"

/**
 * *get_nodeint_at_index - returns the nth node of the listint list
 * @head: - head pointer
 * @index: - index
 * Return:void
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *current_node;

	current_node = head;

	for (i = 0; current_node != NULL && i < index; i++)
	{
	current_node = current_node->next;
	}

	if (i == index && current_node != NULL)
	{
	return (current_node);
	}
	else
	{
	return (NULL);
	}
}

