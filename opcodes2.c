#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 *
 * Return: Nothing (void)
 */

void swap(stack_t **stack, unsigned int nline)
{
	int temp;

	if (stack == NULL || *stack == NULL || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * addop - adds the top two elements of the stack
 * @stack: pointer to the head node
 * @nline: line number;
 *
 * Return: Nothing (void)
 */

void addop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * nop - doesn’t do anything.
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 *
 * Return: Nothing.
 */
void nop(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
}

/**
 * qpush - pushes for queue instead of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */

void qpush(stack_t **stack, unsigned int nline)
{
	stack_t *last, *new;

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
	last = NULL;
	if (*stack)
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*stack = new;
	new->prev = last;
	new->next = NULL;
	new->n = arg.arg;
}
