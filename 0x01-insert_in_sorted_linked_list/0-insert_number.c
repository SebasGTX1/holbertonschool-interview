#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to the head of the list
 * @number: number to insert
 * Return: the address of the new node, or NULL if it failed
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *current = *head;
	listint_t *previous = NULL;

	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (current != NULL)
	{
		if (current->n > number)
		{
			if (previous == NULL)
			{
				new_node->next = current;
				*head = new_node;
				return (new_node);
			}
			else
			{
				new_node->next = current;
				previous->next = new_node;
				return (new_node);
			}
		}
		previous = current;
		current = current->next;
	}
	previous->next = new_node;
	return (new_node);
}