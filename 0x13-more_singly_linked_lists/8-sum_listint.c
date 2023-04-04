#include "lists.h"

/**
 * sum_listint - Computes the sum of all the data of a listint_t linked list.
 *
 * @head: A pointer to the head node of the list.
 *
 * Return: The sum of all the data of the list, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
	sum += head->n;
	head = head->next;
	}

	return (sum);
}

