#include "monty.h"

/**
 * no_int_error - prints invalid _push argumen errors to stderr
 * @line_number: the line number where the error occured
 * Return: EXIT_FAILURE
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

