#include "monty.h"
int data_num;
char *argument;
unsigned int mode;

void push(stack_t **top, unsigned int line_number)
{
	data_num = atoi(argument);
	if (data_num == 0 && (strcmp(argument, "0") != 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (mode == 0)
		add_element(top, data_num);
	else if (mode == 1)
		add_element_end(top, data_num);
}

void pall(stack_t **top, unsigned int line_number __attribute__((unused)))
{
	p_stack_t(*top);
}

void pint(stack_t **top, unsigned int line_number)
{
	int top_val;
	stack_t *head;

	head = *top;
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	top_val = head->n;
	printf("%d\n", top_val);
}

void pop(stack_t **top, unsigned int line_number)
{
	if ((*top) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_element(top, 0);
}

void swap(stack_t **top, unsigned int line_number)
{
	int temp;
	stack_t *head;

	head = *top;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	temp = head->n;
	head->n = head->next->n;
	head->next->n = temp;
}
