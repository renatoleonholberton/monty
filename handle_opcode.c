#include "monty.h"

/**
 * handle_opcode - Receives an opcode and performs an operation based on it
 * @opcode: String representing a monty opcode
 * @line_num: Number of instruction lines
 *
 * Return: 1 if the opcode was found, 0 otherwise
*/
int handle_opcode(char *opcode, int line_num)
{
	int i;
	instruction_t instructions[] = {
		{"pall", print_all},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(&(manager.stack_head), line_num);
			return (1);
		}

	return (0);
}
