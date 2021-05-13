#include "monty.h"

/**
 * parse_input_file - Parses the file line by line
*/
void parse_input_file(void)
{
	int line_number = 1;

	while (getline(&(manager.buff), &(manager.buff_size), manager.file) != EOF)
		parse_line(line_number++);
}

/**
 * parse_line - Parses each line as monty opcodes
 * @line_number: Number of instruction line
*/
void parse_line(int line_number)
{
	int valid_opcode;
	char *tkn = strtok(manager.buff, "\n");

	tkn = strtok(manager.buff, " ");
	if (tkn == NULL || *tkn == '\n') /* blank line */
		return;

	/* Treat line as a comment if the first char is '#' */
	if (*tkn == '#' || strcmp(tkn, "nop") == 0)
		return;

	/* Handle operation mode: stack or queue */
	if (strcmp(tkn, "stack") == 0)
	{
		manager.mode = MODE_STACK;
		return;
	}
	if (strcmp(tkn, "queue") == 0)
	{
		manager.mode = MODE_QUEUE;
		return;
	}

	if (strcmp(tkn, "push") == 0)
	{
		tkn = strtok(NULL, " ");
		if (tkn == NULL || !is_number(tkn))
			err_line(": usage: push integer\n", line_number);

		if (manager.mode == MODE_STACK)
			insert_end(&(manager.stack_head), atoi(tkn));
		else if (manager.mode == MODE_QUEUE)
			insert_start(&(manager.stack_head), atoi(tkn));
		return;
	}
	/*Validate the operation codes*/
	valid_opcode = handle_opcode(tkn, line_number);
	if (!valid_opcode)
		err_invalid_opcode(tkn, line_number);
}
