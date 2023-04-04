#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to the beginning of the list
 *
 * Return: address of the node where the loop starts or NULL if there's no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *lion, *hyena;

	lion = hyena = head;
	while (lion && hyena && hyena->next)
	{
		lion = lion->next;
		hyena = hyena->next->next;
		if (lion == hyena)
		{
			lion = head;
			break;
		}
	}
	if (!lion || !hyena || !hyena->next)
		return (NULL);
	while (lion != hyena)
	{
		lion = lion->next;
		hyena = hyena->next;
	}
	return (hyena);
}
