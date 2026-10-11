#include "monty.h"

/**
 * pall - prints all the values on the stack, from top to bottom
 * @stack: double pointer to the top of the stack
 * @line_number: the line number in the file (unused here)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
