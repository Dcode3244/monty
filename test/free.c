#include "monty.h"

/**
 * free_stack - frees tje stack
 * @stack: the stack to be freed
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = temp->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * free_tokens - frees tokens
 */
void free_tokens(void)
{
	int i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);

	free(tokens);
}
