#include "lists.h"


/**
 * free_listint - fuction that free listint_t list
 * @head:-pointer to the heade of the node
 * Return:void
 */

void free_listint(listint_t *head)
{
	listint_t *present_node;

	while (head != NULL)
	{
		present_node = head;
		head = head->next;
		free(present_node);
	}
}
