#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define DELIMS " \n\t\a\b"

extern char **tokens;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**/
char **_strtok(char *str, char *delim);
int word_count(char *str, char *delim);
char *get_word(char *str, char *delim);
bool check_delim(char c, char *delim);
int word_len(char *str, char *delim);
int monty(FILE *fp);
void free_tokens(void);

/**/
int initialize(stack_t **stack);
int check_mode(stack_t *stack);
void (*opcode_funcs(char *opcode))(stack_t**, unsigned int);
int is_empty(char *line, char *delims);
void set_op_tok_error(int error_code);
void _push(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);

/**/
void _pall(stack_t **stack, unsigned int line_number);



char *get_int(int num);
unsigned int token_arr_len(void);
/* error codes */
int usage_error(void);
int open_error(char *file);
int invalid_op_error(char *opcode, unsigned int line_number);
int malloc_error(void);
int opcode_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

#endif
