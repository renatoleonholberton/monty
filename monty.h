#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct manager_s - main stuct to handle all operations
 * @stack_head: Pointer to the stack's head
 * @buff: Pointer to Buffer
 * @buff_size: Length of buffer
 * @file: Pointer to file struct
 *
 * Description: structure containing all info to manage
 * all operations needed to be performed
 */
typedef struct manager_s
{
	stack_t *stack_head;

	char *buff;
	size_t buff_size;

	FILE *file;
} manager_t;

/* parsers */
void parse_input_file(void);
void parse_line(int line_number);

/* functions */
int handle_opcode(char *opcode, int line_num);

/* stack functions */
void insert_end(stack_t **head, int value);

/* opcode functions */
void print_all(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void div_op(stack_t **head, unsigned int line_number);
void mul_op(stack_t **head, unsigned int line_number);
void mod_op(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);

/* memory */
void cleanup(void);

/* errors */
void err_argc(void);
void err_open_file(char *);
void err_invalid_opcode(char *opcode, int line_number);
void err_malloc(void);
void err_line(char *msg, int line_number);

/* utils */
int is_number(char *str);
char *num_to_str(int num);

/* Global var */
manager_t manager;

#endif
