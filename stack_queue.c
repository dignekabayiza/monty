#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @head: double pointer to the top of the stack
 * @line_number: the line number in the file (unused)
 */
void stack_mode(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	queue_mode = 0;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @head: double pointer to the top of the stack
 * @line_number: the line number in the file (unused)
 */
void queue_op(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	queue_mode = 1;
}
