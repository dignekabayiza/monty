#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the top of the stack
 * @line_number: the line number in the file, used for error messages
 *
 * Description: the result is stored in the second top element, and the
 * top element is removed
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	top->next->n = top->next->n * top->n;

	*stack = top->next;
	(*stack)->prev = NULL;

	free(top);
}
