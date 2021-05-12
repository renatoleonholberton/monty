#include "monty.h"

void print_all(stack_t **stack_tail, unsigned int line_number)
{
	stack_t *tail;

	if (stack_tail == NULL || *stack_tail == NULL)
		return;
	
	tail = *stack_tail;
	while (tail != NULL)
	{
		printf("%d\n", tail->n);
		tail = tail->prev;
	}
}
