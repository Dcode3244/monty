#include "monty.h"

/**
 * usage_error - prints usage error message to stderr
 * Return: EXIT_FAILURE
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * open_error - Prints file opening error messages to stderr
 * @file: the file name that failed to open
 * Return: EXIT_FAILURE
 */
int open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s", file);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error message to stderr
 * Return: EXIT_FAILURE
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}


/**
 * opcode_error - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number where the error occured.
 * Return: EXIT_FAILURE
 */
int opcode_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}
