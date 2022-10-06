#include "monty.h"

/**
 * free_tokens - Frees the global opcode_toks array of strings.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (opcode_toks == NULL)
		return;

	for (i = 0; opcode_toks[i]; i++)
		free(opcode_toks[i]);

	free(opcode_toks);
}

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
