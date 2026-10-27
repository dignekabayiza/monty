#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: the line number in the file (unused)
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)line_number;

	node = *stack;
	while (node != NULL && node->n > 0 && node->n <= 127)
	{
		putchar(node->n);
		node = node->next;
	}
	putchar('\n');
}
