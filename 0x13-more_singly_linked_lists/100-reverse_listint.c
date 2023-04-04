#include "lists.h"
/**
 * reverse_listint - reverses a listint_t linked list
 * @head: double pointer to head
 * Return: address of head of list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *next_destination = NULL, *tmpd = NULL, *current = *head;

	if (!head || !(*head))
		return (*head);

	next_destination = current->next;
	current->next = NULL;

	while (next_destination)
	{
		tmpd = next_destination->next;
		next_destination->next = current;
		current = next_destination;
		next_destination = tmpd;
	}
	*head = current;

	return (*head);
}
