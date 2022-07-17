#include "monty.h"

int data_num;
char *argument;
unsigned int mode;

/**
 * push - Pushes a number to the stack(or queue)
 * @top: Pointer to pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 * Return: Void.
 */

void push(stack_t **top, unsigned int line_number)
{
	int i;

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	for (i = 0; argument[i] != '\0'; i++)
		if (argument[i] != '-' &&
		    (argument[i] < '0' || argument[i] > '9'))
		{
			fprintf(stderr, "L%d: usage: push integer\n",
				line_number);
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
	data_num = atoi(argument);
	if (data_num == 0 && (strcmp(argument, "0") != 0)
	    && (strcmp(argument, "-0")))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	if (mode == 0)
		add_element(top, data_num);
	else if (mode == 1)
		add_element_end(top, data_num);
}

/**
 * pall - prints all the values on the stack, starting from the top of the stack
 * @top: Pointer to pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 * Return: Void.
 */

void pall(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	p_stack_t(*top);
}

/**
 * pint - prints the value at the top of the stack(or queue)
 * @top: Pointer to pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 * Return: Void.
 */

void pint(stack_t **top, unsigned int line_number)
{
	int top_val;
	stack_t *head;

	head = *top;
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	top_val = head->n;
	printf("%d\n", top_val);
}

/**
 * pop - removes the top element of the stack(or queue)
 * @top: Pointer to pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 * Return: Void.
 */

void pop(stack_t **top, unsigned int line_number)
{
	if ((*top) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	delete_element(top, 0);
}

/**
 * swap -swaps the top two elements of the stack(or queue)
 * @top: Pointer to pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 * Return: Void.
 */

void swap(stack_t **top, unsigned int line_number)
{
	int temp;
	stack_t *head;

	head = *top;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	temp = head->n;
	head->n = head->next->n;
	head->next->n = temp;
}
