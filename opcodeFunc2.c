#include "monty.h"

/**
 *
 *
 */
void Func_swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, val;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		free(*head);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	val = temp->n;
	temp->n = temp->next->n;
	temp->next->n = val;
}
