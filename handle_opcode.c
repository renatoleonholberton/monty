#include "monty.h"

extern manager_t manager;

int handle_opcode(char *opcode, int line_num)
{
	int i;
	instruction_t instructions[] = {
		{"pall", print_all},
		{"pint", pint},
		{"pop", pop},
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
