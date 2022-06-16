#include "lists.h"

/**
 * Insert_node: Inserts new node
 * 
 * @head: Head of a list.
 * @number: Index of the list where the new node is
 * added.
 * Return: Address of the new node, or NULL if it
 * failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *h;
	listint_t *h_prep;

	h = *head;
	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	while (h != NULL)
	{
		if (h->n > number)
			break;
		h_prep = h;
		h = h->next;
	}

	new_node->n = number;

	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = h;
		if (h == *head)
			*head = new_node;
		else
			h_prep->next = new_node;
	}

	return (new_node);
}

