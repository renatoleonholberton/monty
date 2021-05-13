#include "monty.h"

/**
 * err_argc - Prints an error message to stderr
*/
void err_argc(void)
{
	char *msg = "USAGE: monty file\n";

	write(2, msg, strlen(msg));
	exit(EXIT_FAILURE);
}

/**
 * err_open_file - Prints an error message to stderr
 * @file: String representing a file path
*/
void err_open_file(char *file)
{
	char *msg = "Error: Can't open file ";

	write(2, msg, strlen(msg));
	write(2, file, strlen(file));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

/**
 * err_push_arg - Prints an error message to stderr
 * @line_number: Number of instruction line
*/
void err_push_arg(int line_number)
{/* L<line_number>: usage: push integer */
	char *msg;

	write(2, "L", 1);
	msg = num_to_str(line_number);
	write(2, msg, strlen(msg));
	free(msg);
	msg = ": usage: push integer\n";
	write(2, msg, strlen(msg));
	cleanup();
	exit(EXIT_FAILURE);
}

/**
 * err_invalid_opcode - Prints an error message to stderr
 * @opcode: String representing an monty opcode
 * @line_number: Number of instruction line
*/
void err_invalid_opcode(char *opcode, int line_number)
{/* L<line_number>: unknown instruction <opcode> */
	char *msg;

	write(2, "L", 1);
	msg = num_to_str(line_number);
	write(2, msg, strlen(msg));
	free(msg);
	msg = ": unknown instruction ";
	write(2, msg, strlen(msg));
	write(2, opcode, strlen(opcode));
	write(2, "\n", 1);
	cleanup();
	exit(EXIT_FAILURE);
}

/**
 * err_malloc - Prints an error message to stderr
*/
void err_malloc(void)
{
	char *msg = "Error: malloc failed\n";

	write(2, msg, strlen(msg));
	cleanup();
	exit(EXIT_FAILURE);
}
