#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>


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

/**
 * arg_s - doubly linked list representation of a stack (or queue)
 * @arg: argument
 * @flag: flag
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct arg_s
{
	int arg;
	int flag;
} arg_t;

extern arg_t arg;

/**
 * struct line - contents of line and corresponding number
 * @content: array of tokens read from the line
 * @number: the line number
 *
 * Description: contents of a line and corresponding number
 */

typedef struct line
{
	unsigned int number;
	char **content;
} line_t;

/**
 * meta_s - doubly linked list representation of a stack (or queue)
 * @buf: integer
 * @stack: points to the previous element of the stack (or queue)
 * @file: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct meta_s
{
	char *buf;
	stack_t *stack;
	FILE *file;
} meta_t;

void (*get_op_func(line_t line, meta_t *meta))(stack_t **, unsigned int);
void parsefile(FILE *file);
bool comment_check(line_t line);
void push_check(line_t line, meta_t *meta, char *opcode);
bool argument_check(char *token);
void parseline(line_t *line, char *buffer);
int _isalpha(int c);

void push(stack_t **stack, unsigned int nline);
void pall(stack_t **stack, unsigned int nline);
void pint(stack_t **stack, unsigned int nline);
void pop(stack_t **stack, unsigned int nline);
void swap(stack_t **stack, unsigned int nline);
void addop(stack_t **stack, unsigned int nline);
void nop(stack_t **stack, unsigned int nline);
void free_stack(stack_t **stack);
void qpush(stack_t **stack, unsigned int nline);

#endif /* MONTY_H */
