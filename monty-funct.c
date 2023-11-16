#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script file.
 * @arg: The argument to be pushed.
 */
void push(stack_t **stack, unsigned int line_number, const char *arg)
{
	int num;
	stack_t *new_node;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(arg);
	if (num == 0 && strcmp(arg, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - Prints all values on the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
