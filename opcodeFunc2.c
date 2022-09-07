#include "monty.h"
<<<<<<< HEAD

/**
 *
 *
 */
void Func_swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, val;
=======
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
>>>>>>> f3b219869a28f04a7388b999f0c238aa65127879

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
<<<<<<< HEAD
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
=======
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
>>>>>>> f3b219869a28f04a7388b999f0c238aa65127879
		free(*head);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
<<<<<<< HEAD
	val = temp->n;
	temp->n = temp->next->n;
	temp->next->n = val;
=======
	(*head)->prev = (*head)->next;
	(*head)->next = temp->next;
	temp->prev = NULL;
	(*head)->prev = temp;
	if (temp->next)
		temp->next->prev = *head;
	temp->next = *head;
	(*head) = (*head)->prev;
>>>>>>> f3b219869a28f04a7388b999f0c238aa65127879
}
