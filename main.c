#include "monty.h"

/**
 * main - Entry point
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 *
 * Return: 0 on success, err code otherwise
*/
int main(int argc, char **argv)
{
	if (argc != 2)
		err_argc();

	manager.stack_head = NULL;
	manager.buff = NULL;
	manager.buff_size = 0;
	manager.file = NULL;
	manager.mode = MODE_STACK;

	manager.file = fopen(argv[1], "r");
	if (manager.file == NULL)
		err_open_file(argv[1]);

	parse_input_file();

	cleanup();
	return (0);
}
