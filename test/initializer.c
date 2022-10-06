#include "monty.h"

/**
 * initialize - initializes a stack
 * @stack: the stack to be initialized
 * Return: EXIT_SUCCESS if succesfull, else EXIT_ERROR
 */
int initialize(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));

	if (s == NULL)
		return (malloc_error());

	s->n = 1;
	s->next = NULL;
	s->prev = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - checks if stack is a stack or a queue
 * @stack: the stack to be checked
 * Return: 1 if stack 0 if queue else 2
 */
int check_mode(stack_t *stack)
{
	if (stack->n == 1)
		return (1);
	else if (stack->n == 0)
		return (0);
	return (2);
}
