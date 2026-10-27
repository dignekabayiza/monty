#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the top of the stack
 * @line_number: the line number in the file (unused)
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;

	*stack = top->next;
	(*stack)->prev = NULL;
	top->next = NULL;
	top->prev = last;
	last->next = top;
}
