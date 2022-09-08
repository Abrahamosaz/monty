#include "monty.h"

/**
 * Func_push - inserts a value into stack
 * @head: pointer to head node address
 * @line_number: line number
 */
void Func_push(stack_t **head, unsigned int line_number)
{
	stack_t *new_stack =  NULL, *dir = *head;

	(void)line_number;
	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
		ErrorHandler(3, NULL, 0);
	new_stack->next = NULL;
	new_stack->n = stack_value;
	if (head && !*head)
	{
		new_stack->prev = NULL;
		*head =  new_stack;
		return;
	}
	while (dir->next)
		dir = dir->next;
	new_stack->prev =  dir;
	dir->next = new_stack;
}

/**
 * pall_rec - recursive function to print stack elements
 *
 * @head: pointer to head node
 *
 */
static
void pall_rec(stack_t *head)
{
	if (!head)
		return;
	pall_rec(head->next);
	printf("%d\n", head->n);
}

/**
 * Func_pall - prints all elements in stack
 * @head: pointer to head node
 * @line_number: line number
 */
void Func_pall(stack_t **head, unsigned int line_number)
{
	if (!*head)
		return;
	(void)line_number;
	pall_rec(*head);
}

/**
 * Func_pop - removes last element from stack
 * @head: pointer to head node address
 * @line_number: specific line
 */
void Func_pop(stack_t **head, unsigned int line_number)
{
	int count;
	stack_t *dir = *head;

	count = CountStack(head);
	if (!count)
		ErrorHandler(5, NULL, line_number);
	else if (count == 1)
	{
		free(*head);
		*head = NULL;
		return;
	}
	while (dir->next)
		dir = dir->next;
	dir->prev->next = NULL;
	free(dir);
}

/**
 * Func_pint - prints element at top of stack
 * @head: pointer to head node address
 * @line_number: specific line number
 */
void Func_pint(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head;

	if (!CountStack(head))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (dir->next)
		dir = dir->next;
	printf("%d\n", dir->n);
}
