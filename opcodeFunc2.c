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
 *
 *
 *
 */
void Func_swap(stack_t **head, unsigned int line_number)
{
<<<<<<< HEAD
	stack_t *temp;
<<<<<<< HEAD
	int len = 0;
>>>>>>> f3b219869a28f04a7388b999f0c238aa65127879
=======
	int len = 0, val;
>>>>>>> f6aea29d3e1990894c01389f8743cceed28abf32
=======
	stack_t *dir = *head, *prev = NULL;
	int temp;
>>>>>>> 3c8b99be47ae2a80ef61a49f06cf9ff5337c983f

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (dir->next)
		dir = dir->next;
	prev =  dir->prev;
	temp  = prev->n;
	prev->n = dir->n;
	dir->n = temp;
}
/**
 *
 *
 */
void Func_add(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int result;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (dir->next)
		dir = dir->next;
	prev = dir->prev;
	result =  prev->n + dir->n;
	prev->n = result;
	free(dir);
	prev->next = NULL;
}
/**
 *
 */
void Func_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
/**
 *
 */
void Func_sub(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int result;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (dir->next)
		dir = dir->next;
	prev = dir->prev;
	result =  (prev->n) - (dir->n);
	prev->n = result;
	free(dir);
	prev->next = NULL;
}
/**
 *
 *
 */
void Func_div(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int result;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (dir->next)
		dir = dir->next;
	if (!dir->n)
	{
<<<<<<< HEAD
<<<<<<< HEAD
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
=======
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
>>>>>>> f3b219869a28f04a7388b999f0c238aa65127879
		free(*head);
		exit(EXIT_FAILURE);
	}
<<<<<<< HEAD
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
=======
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	val = temp->prev->n;
	temp->prev->n = temp->next->n;
	temp->next->n = val;
>>>>>>> f6aea29d3e1990894c01389f8743cceed28abf32
=======
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	prev = dir->prev;
	result = (prev->n) / (dir->n);
	prev->n = result;
	free(dir);
	prev->next = NULL;
>>>>>>> 3c8b99be47ae2a80ef61a49f06cf9ff5337c983f
}
