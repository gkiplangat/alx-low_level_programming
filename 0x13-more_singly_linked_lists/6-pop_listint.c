#include "lists.h"

/**
 * pop_listint - deletes the head nodes of listint_t
 * @head: - head pointer
 * Return: void;
 */

int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (head == NULL || *head == NULL)
	return (0);

	temp = *head;
	*head = temp->next;
	data = temp->n;
	free(temp);

	return (data);
}
