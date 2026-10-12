#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: the line number in the file, used for error messages
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack = second;
}
