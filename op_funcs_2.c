#include "monty.h"

/**
 * sub - Subtracts the top 2 elements of the stack
 * @head: Double pointer to head node
 * @line_number: Number of instruction line
*/
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *curr, *prev = NULL;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		err_line(": can't sub, stack too short\n", line_number);

	for (curr = *head; curr->next != NULL; curr = curr->next)
		prev = curr;

	prev->n = prev->n - curr->n;
	prev->next = NULL;
	curr->prev = NULL;
	free(curr);
}

/**
 * div_op - Divides the secnd top element by the top element of the stack
 * @head: Double pointer to head node
 * @line_number: Number of instruction line
*/
void div_op(stack_t **head, unsigned int line_number)
{
	stack_t *curr, *prev = NULL;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		err_line(": can't div, stack too short\n", line_number);

	for (curr = *head; curr->next != NULL; curr = curr->next)
		prev = curr;

	if (curr->n == 0)
		err_line(": division by zero\n", line_number);

	prev->n = prev->n / curr->n;
	prev->next = NULL;
	curr->prev = NULL;
	free(curr);
}

/**
 * mul_op - Multiplies the second top element with the top element of the stack
 * @head: Double pointer to head node
 * @line_number: Number of instruction line
*/
void mul_op(stack_t **head, unsigned int line_number)
{
	stack_t *curr, *prev = NULL;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		err_line(": can't mul, stack too short\n", line_number);

	for (curr = *head; curr->next != NULL; curr = curr->next)
		prev = curr;

	prev->n = prev->n * curr->n;
	prev->next = NULL;
	curr->prev = NULL;
	free(curr);
}
