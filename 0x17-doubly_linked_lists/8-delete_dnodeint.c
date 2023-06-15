#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at given index of a list
 * @head: pointer to head of the list
 * @index: index to delete from, starting from 0
 * Return: 1 on success elsewhere -1 on failure
 **/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int c_count;
	dlistint_t *temp;

	if (*head == NULL || head == NULL)
	return (-1);
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(temp), temp = NULL;
		return (1);
	}
	c_count = 1, temp = (*head)->next;
	if (temp)
	{
		while (temp->next)
		{
			if (index == c_count)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				free(temp), temp = NULL;
				return (1);
			}
			c_count++, temp = temp->next;
		}
	}
	if (temp && index == c_count)
	{
		temp->prev->next = NULL;
		free(temp);
		return (1);
	}
	return (-1);
}
