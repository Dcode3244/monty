#include "monty.h"
#include <unistd.h>

char **tokens = NULL;
/**
 * main - entrance point to monty interpreter
 * @ac: number of comand line arguments
 * @av: the command line arguments
 * Return: exit status
 */
int main(int ac, char **av)
{
	FILE *fp = NULL;
	int ret;

	if (ac != 2)
		return (usage_error());
	fp = fopen(av[1], "r");
	if (fp == NULL)
		return (open_error(av[1]));

	ret = monty(fp);
	fclose(fp);

	return (ret);
}

/**
 * monty - monty language interpreter
 * @fp: name of file containint monty code
 * Return: EXIT_SUCCESS if successfull EXIT_FAILURE if failed
 */
int monty(FILE *fp)
{
	size_t exit_code = EXIT_SUCCESS;
	char *line = NULL;
	size_t n = 0;
	unsigned int line_number = 0, prev_tok_len = 0;
	stack_t *stack = NULL;
	void (*opcode_func)(stack_t**, unsigned int);

	if (initialize(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&line, &n, fp) != -1)
	{
		line_number++;
		tokens = _strtok(line, DELIMS);
		if (tokens == NULL)
		{
			if (is_empty(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (tokens[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		opcode_func = opcode_funcs(tokens[0]);
		if (opcode_func == NULL)
		{
			free_stack(&stack);
			exit_code = opcode_error(tokens[0], line_number);
			free_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		opcode_func(&stack, line_number);
		if (token_arr_len() != prev_tok_len)
		{
			if (tokens && tokens[prev_tok_len])
				exit_code = atoi(tokens[prev_tok_len]);
			else
				exit_code = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);
	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}
	free(line);
	return (exit_code);
}

/**
 * is_empty - checks if a line is containing only delimeters
 * @line: the line to be checked
 * @delims: string containing delimeters
 * Return: 1 if line is empty, else 0
 */
int is_empty(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	return (1);
}

/**
 * opcode_funcs - functions pointer
 * @opcode: monty opcode
 * Return: NULL if failed, opcode funtions if succesfull
 */
void (*opcode_funcs(char *opcode))(stack_t**, unsigned int)
{
	int i;
	instruction_t opcode_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	for (i = 0; opcode_funcs[i].opcode; i++)
	{
		if ((strcmp(opcode, opcode_funcs[i].opcode)) == 0)
			return (opcode_funcs[i].f);
	}

	return (NULL);
}

/**
 * token_arr_len - gets the length of the current tokens
 * Return: lenght of the token
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (tokens[toks_len])
		toks_len++;
	return (toks_len);
}
