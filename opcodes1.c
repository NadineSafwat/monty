#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 *
 * Return: Nothing (void)
 */
void push(stack_t **stack, unsigned int nline)
{
	stack_t *new;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->next = *stack;
	new->prev = NULL;
	new->n = arg.arg;
	if (*stack)
	{
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * pall - prints all the values on the stack, starting
 * from the top of the stack.
 * @stack: pointer to the head node pointer of stack
 * @nline: the number of line
 *
 * Return: Nothing (void)
 */

void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack,
 * followed by a new line.
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 *
 *  Return: Nothing (void)
 */

void pint(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
		{
			break;
		}
		temp = temp->prev;
	}
	printf("%d\n", temp->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 *
 * Return: Nothing.
 */

void pop(stack_t **stack, unsigned int nline)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", nline);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
