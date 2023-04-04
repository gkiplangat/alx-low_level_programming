#include "lists.h"

/**
 * free_listint2 - free listint list
 * @head: - head pointer
 * Return:void
 */

void free_listint2(listint_t **head)
{
	listint_t *present_node, *next_node;

	if (head == NULL)
	return;

	present_node = *head;

	while (present_node != NULL)
	{
		next_node = present_node->next;
		free(present_node);
		present_node = next_node;
	}
	*head = NULL;
}
