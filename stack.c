#include "monty.h"

void insert_end(stack_t **head_addrs, stack_t **tail_addrs, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		err_malloc();
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*head_addrs == NULL)
	{
		*head_addrs = new_node;
		*tail_addrs = new_node;
		return;
	}

	new_node->prev = *tail_addrs;
	(*tail_addrs)->next = new_node;
	*tail_addrs = new_node;
}
