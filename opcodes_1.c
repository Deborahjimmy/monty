#include "monty.h"

void add(stack_t **top, unsigned int line_number)
{
	int top_val;

	if ((*top) == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	top_val = (*top)->n;
	delete_element(top, 0);
	(*top)->n += top_val;
}

void nop(stack_t **top __attribute__((unused)),
	 unsigned int line_number __attribute__((unused)))
{
}

void sub(stack_t **top, unsigned int line_number)
{
	int top_val;

	if ((*top) == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	top_val = (*top)->n;
	delete_element(top, 0);
	(*top)->n -= top_val;
}

void divd(stack_t **top, unsigned int line_number)
{
	int top_val;

	if ((*top) == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	top_val = (*top)->n;
	if (top_val == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_element(top, 0);
	(*top)->n /= top_val;
}

void mul(stack_t **top, unsigned int line_number)
{
        int top_val;

        if ((*top) == NULL || (*top)->next == NULL)
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n",
                        line_number);
                exit(EXIT_FAILURE);
        }

	top_val = (*top)->n;
        delete_element(top, 0);
        (*top)->n *= top_val;
}
