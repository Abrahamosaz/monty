#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int len = 0;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		free(*head);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	(*head)->prev = (*head)->next;
	(*head)->next = temp->next;
	temp->prev = NULL;
	(*head)->prev = temp;
	if (temp->next)
		temp->next->prev = *head;
	temp->next = *head;
	(*head) = (*head)->prev;
}
