#include "monty.h"
/**
 *
 *
 */
void Func_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *top_ptr = NULL, *temp_ptr = NULL;

	(void)line_number;
	top_ptr = malloc(sizeof(top_ptr));
	if (!top_ptr)
		ErrorHandler(3, NULL, 0);
	while (dir->next)
		dir = dir->next;
	top_ptr->n = dir->n;
	top_ptr->prev = NULL;
	top_ptr->next = *head;
	(*head)->prev = top_ptr;
	temp_ptr = dir->prev;
	*head = top_ptr;
	free(dir);
	temp_ptr->next = NULL;
}
