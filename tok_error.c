#include "monty.h"

/**
 * set_op_tok_error - sets last element of tokens to be an error code
 * @error_code: int t store as a string in tokens
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!tokens)
	{
		malloc_error();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = tokens[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(tokens);
	tokens = new_toks;
}
