#include "monty.h"

/**
 * mod - computes the rest of the division of the
 * second top element of the stack.
 *
 * @top: Pointer to pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 * Return: Void.
 */

void mod(stack_t **top, unsigned int line_number)
{
	int top_val;

	if ((*top) == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	top_val = (*top)->n;
	if (top_val == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	delete_element(top, 0);
	(*top)->n %= top_val;
}

/**
 * pchar - Print the first element as an ASCII character(or queue)
 * @top: Pointer to pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 * Return: Void.
 */

void pchar(stack_t **top, unsigned int line_number)
{
	int top_val;

	if ((*top) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	top_val = (*top)->n;
	if (top_val < 1 || top_val > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	putchar(top_val);
	putchar('\n');
}

/**
 * pstr - Print the element of the stack as an ASCII(or queue)
 * @top: Pointer to pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 * Return: Void.
 */

void pstr(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	int top_val;
	stack_t *current;

	current = *top;
	while (current)
	{
		if (current == NULL)
			break;
		top_val = current->n;
		if (top_val < 1 || top_val > 127)
			break;
		putchar(top_val);
		current = current->next;
	}
	putchar('\n');
}

/**
 * rotl - rotate the element to the stack to the top(or queue)
 * @top: Pointer to pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 * Return: Void.
 */

void rotl(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	stack_t *head, *tail;

	head = tail = *top;
	if (head != NULL)
	{
		while (tail->next)
			tail = tail->next;
		tail->next = head;
		head->prev = tail;
		*top = head->next;
		(*top)->prev = NULL;
		head->next = NULL;
	}
}

/**
 * rotr - rotates the stack to the bottom.
 * @top: Pointer to pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 * Return: Void.
 */

void rotr(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	stack_t *head, *tail;

	head = tail = *top;
	if (head != NULL)
	{
		while (tail->next)
			tail = tail->next;
		tail->next = head;
		head->prev = tail;
		tail->prev->next = NULL;
		tail->prev = NULL;
		*top = tail;
	}
}
