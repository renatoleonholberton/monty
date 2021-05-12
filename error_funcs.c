#include "monty.h"

void err_argc()
{
	char *msg = "USAGE: monty file\n";

	write(2, msg, _strlen(msg));
	exit(EXIT_FAILURE);
}

void err_open_file(char *file)
{
	char *msg = "Error: Can't open file ";

	write(2, msg, _strlen(msg));
	write(2, file, _strlen(file));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void err_push_arg(int line_number)
{/* L<line_number>: usage: push integer */
	char *msg;

	write(2, "L", 1);
	msg = num_to_str(line_number);
	write(2, msg, _strlen(msg));
	free(msg);
	msg = ": usage: push integer\n";
	write(2, msg, _strlen(msg));
	cleanup();
	exit(EXIT_FAILURE);
}

void err_invalid_opcode(char *opcode, int line_number)
{/* L<line_number>: unknown instruction <opcode> */
	char *msg;

	write(2, "L", 1);
	msg = num_to_str(line_number);
	write(2, msg, _strlen(msg));
	free(msg);
	msg = ": unknown instruction ";
	write(2, msg, _strlen(msg));
	write(2, opcode, _strlen(opcode));
	write(2, "\n", 1);
	cleanup();
	exit(EXIT_FAILURE);
}

void err_malloc()
{
	char *msg = "Error: malloc failed\n";
	
	write(2, msg, _strlen(msg));
	cleanup();
	exit(EXIT_FAILURE);
}
