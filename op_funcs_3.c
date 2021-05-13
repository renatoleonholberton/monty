#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack
 * @head: Double pointer to head node
 * @line_number: Number of instruction line
*/
void pstr(stack_t **head, unsigned int __attribute__((unused)) line_number)
{
	stack_t *curr;

	if (head == NULL || *head == NULL)
	{
		printf("\n");
		return;
	}

	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;

	while (curr != NULL)
	{
		if (curr->n <= 0 || curr->n > 127)
			break;
		printf("%c", curr->n);
		curr = curr->prev;
	}

	printf("\n");
}

/**
 * rotl - Rotates the stack by one element top to bottom
 * @head: Double pointer to head node
 * @line_number: Number of instruction line
*/
void rotl(stack_t **head, unsigned int __attribute__((unused)) line_number)
{
	stack_t *curr, *prev;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	for (curr = *head; curr->next != NULL; curr = curr->next)
		prev = curr;

	prev->next = NULL;
	curr->prev = NULL;
	curr->next = *head;
	(*head)->prev = curr;
	*head = curr;
}

/**
 * rotr - Rotates the stack by one element bottom to top
 * @head: Double pointer to head node
 * @line_number: Number of instruction line
*/
void rotr(stack_t **head, unsigned int __attribute__((unused)) line_number)
{
	stack_t *last, *first;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	last = *head;
	while (last->next != NULL)
		last = last->next;

	first = *head;
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

/**
 * print_queue - Print the stack as a queue
 * @head: Double pointer to head node
 * @line_num: Number of instruction line
*/
void print_queue(stack_t **head, unsigned int __attribute__((unused)) line_num)
{
	stack_t *curr;

	if (head == NULL || *head == NULL)
		return;

	curr = *head;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
