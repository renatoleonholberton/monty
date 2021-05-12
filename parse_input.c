#include "monty.h"

extern manager_t manager;

void parse_input_file()
{
	int line_number = 1;

	while (getline(&(manager.buff), &(manager.buff_size), manager.file) != EOF)
		parse_line(line_number++);
}

void parse_line(int line_number)
{
	int valid_opcode;
	char *tkn = strtok(manager.buff, "\n");
	
	tkn = strtok(manager.buff, " ");
	if (tkn == NULL || *tkn == '\n') /* blank line */
		return;

	if (strcmp(tkn, "push") == 0)
	{
		tkn = strtok(NULL, " ");
		if (tkn == NULL || !is_number(tkn))
			err_push_arg(line_number);
		
		insert_end(&(manager.stack_head), atoi(tkn));
		return;
	}

	valid_opcode = handle_opcode(tkn, line_number);
	if (!valid_opcode)
		err_invalid_opcode(tkn, line_number);
}
