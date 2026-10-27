#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the top of the stack
 * @line_number: the line number in the file (unused)
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
