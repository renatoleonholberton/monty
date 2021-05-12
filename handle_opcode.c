#include "monty.h"

int handle_opcode(manager_t manager, char *opcode, int line_num)
{
	int i;
	instruction_t instructions[] = {
		{"pall", print_all},
		{"pint", pint},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(&(manager.stack_tail), line_num);
			return (1);
		}

	return (0);
}
