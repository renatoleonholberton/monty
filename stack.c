#include "monty.h"

/**
 * insert_end - Inserts a node at the end of the stack
 * @head: Double pointer to stack's head
 * @value: Value nu,ber to add to the stack
*/
void insert_end(stack_t **head, int value)
{
	stack_t *curr;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		err_malloc();
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;

	curr->next = new_node;
	new_node->prev = curr;
}
