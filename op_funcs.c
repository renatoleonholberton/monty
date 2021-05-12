#include "monty.h"

void print_all(stack_t **stack_tail, unsigned int __attribute__((unused))line_number)
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

/**
 * pint - Prints the value at the top of the stack
 * @stack_tail: Double pointer to the stack's tail
 * @line_number: Number of line instruction
*/
void pint(stack_t **stack_tail, unsigned int line_number)
{
	stack_t *tail;

	if (stack_tail == NULL || *stack_tail == NULL)
		err_pint(line_number);
	
	tail = *stack_tail;
	printf("%d\n", tail->n);
}
