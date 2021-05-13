#include "monty.h"

/**
 * err_pint - Prints an error to stderr
 * @line_number: Number of instruction line
*/
void err_pint(int line_number)
{/* L<line_number>: can't pint, stack empty */
	char *msg;

	write(2, "L", 1);
	msg = num_to_str(line_number);
	write(2, msg, strlen(msg));
	free(msg);
	msg = ": can't pint, stack empty\n";
	write(2, msg, strlen(msg));
	cleanup();
	exit(EXIT_FAILURE);
}

/**
 * err_pop - Prints an error to stderr
 * @line_number: Number of instruction line
*/
void err_pop(int line_number)
{/* L<line_number>: can't pop an empty stack */
	char *msg;

	write(2, "L", 1);
	msg = num_to_str(line_number);
	write(2, msg, strlen(msg));
	free(msg);
	msg = ": can't pop an empty stack\n";
	write(2, msg, strlen(msg));
	cleanup();
	exit(EXIT_FAILURE);
}
