#include "monty.h"

/**
 * print_all - Prints the values of the stack from top to bottom
 * @head: Double pointer to head node
 * @line_number: Number of instruction line
*/
void print_all(stack_t **head, unsigned int __attribute__((unused))line_number)
{
	stack_t *curr;

	if (head == NULL || *head == NULL)
		return;

	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @head: Double pointer to head node
 * @line_number: Number of instruction line
*/
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *curr;

	if (head == NULL || *head == NULL)
		err_pint(line_number);

	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;

	printf("%d\n", curr->n);
}

/**
 * pop - Removes the node at the top of the stack
 * @head: Double pointer to the stack's head
 * @line_number: Number of line instruction
*/
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *curr, *prev = NULL;

	if (head == NULL || *head == NULL)
		err_pop(line_number);

	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}

	for (curr = *head; curr->next != NULL; curr = curr->next)
		prev = curr;

	if (prev != NULL)
		prev->next = NULL;
	curr->prev = NULL;
	free(curr);
}

/**
 * swap - Swaps the top 2 elementts of the stack
 * @head: Double pointer to the stack's head
 * @line_number: Number of line instruction
*/
void swap(stack_t **head, unsigned int line_number)
{
	int temp;
	stack_t *curr, *prev = NULL;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		err_swap(line_number);

	for (curr = *head; curr->next != NULL; curr = curr->next)
		prev = curr;

	temp = curr->n;
	curr->n = prev->n;
	prev->n = temp;
}

/**
 * add - Adds the top 2 elementts of the stack
 * @head: Double pointer to the stack's head
 * @line_number: Number of line instruction
*/
void add(stack_t **head, unsigned int line_number)
{
	stack_t *curr, *prev = NULL;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		err_add(line_number);

	for (curr = *head; curr->next != NULL; curr = curr->next)
		prev = curr;

	prev->n = prev->n + curr->n;
	prev->next = NULL;
	curr->prev = NULL;
	free(curr);
}
