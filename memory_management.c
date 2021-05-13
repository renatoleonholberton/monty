#include "monty.h"

extern manager_t manager;

void free_stack(void);

/**
 * cleanup - Frees allocated memory
*/
void cleanup(void)
{
	/* free buffer */
	free(manager.buff);
	/* free stack */
	free_stack();
	/* close file */
	fclose(manager.file);
}

/**
 * free_stack - Frees the memory allocated by the stack
*/
void free_stack(void)
{
	stack_t *curr, *prev = NULL;

	curr = manager.stack_head;

	while (curr != NULL)
	{
		prev = curr;
		curr = curr->next;

		prev->prev = NULL;
		prev->next = NULL;
		free(prev);
	}

	manager.stack_head = NULL;
}
