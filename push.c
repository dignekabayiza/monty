#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: the line number in the file, used for error messages
 *
 * Description: the argument is stored in a global variable set by main
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int i;

	if (current_arg == NULL || *current_arg == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; current_arg[i] != '\0'; i++)
	{
		if (current_arg[i] == '-' && i == 0)
			continue;
		if (current_arg[i] < '0' || current_arg[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(current_arg);
	
	if (queue_mode == 1 && *stack != NULL)
	{
		stack_t *last = *stack;

		while (last->next != NULL)
			last = last->next;
		new_node->prev = last;
		new_node->next = NULL;
		last->next = new_node;
		return;
	}

	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
