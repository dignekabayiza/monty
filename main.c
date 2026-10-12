#include "monty.h"

char *current_arg;

int run_file(const char *filename);

/**
 * main - entry point for the monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	return (run_file(argv[1]));
}

/**
 * run_file - opens and processes a monty bytecode file
 * @filename: path to the file
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int run_file(const char *filename)
{
	FILE *file;
	char line[1024];
	char *opcode;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};
	int i, found;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		current_arg = strtok(NULL, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		found = 0;
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				found = 1;
				break;
			}
		}

		if (!found)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free_stack(stack);
			fclose(file);
			return (EXIT_FAILURE);
		}
	}

	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * free_stack - frees all nodes in the stack
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
