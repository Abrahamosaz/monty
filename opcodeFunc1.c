#include "monty.h"
/**
 *
 *
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
 *
 *
 *
 */
static void pall_rec(stack_t *head)
{
	if (!head)
		return;
	pall_rec(head->next);
	printf("%d\n", head->n);
}
/**
 *
 *
 */
void Func_pall(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	pall_rec(*head);
}

/**
 *
 *
 *
 */
void Func_pint(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int val;

	if (!temp)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		free(*head);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	val = temp->n;
	free(temp);
	printf("%d\n", val);
}
