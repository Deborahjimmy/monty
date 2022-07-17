#include "monty.h"

/**
 * add - adds the top two elements of the stack(or queue)
 * @top: Pointer to pointer to the top of the stack.
 * @line_number:Line number of the instruction.
 * Return:Void.
 */
void add(stack_t **top, unsigned int line_number)
{
	int top_val;

	if ((*top) == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	top_val = (*top)->n;
	delete_element(top, 0);
	(*top)->n += top_val;
}

/**
 * nop - doesn't do anything
 * @top: Pointer to pointer to the top of the stack.
 * @line_number:Line number of the instruction.
 * Return:Void.
 */

void nop(stack_t **top __attribute__((unused)),
	 unsigned int line_number __attribute__((unused)))
{
}

/**
 * sub - subtracts the top element of the stack(or queue)
 * @top: Pointer to pointer to the top of the stack.
 * @line_number:Line number of the instruction.
 * Return:Void.
 */

void sub(stack_t **top, unsigned int line_number)
{
	int top_val;

	if ((*top) == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	top_val = (*top)->n;
	delete_element(top, 0);
	(*top)->n -= top_val;
}

/**
 * divd - Divides the second top element of the stack(or queue)
 * @top: Pointer to pointer to the top of the stack.
 * @line_number:Line number of the instruction.
 * Return:Void.
 */


void divd(stack_t **top, unsigned int line_number)
{
	int top_val;

	if ((*top) == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
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
	(*top)->n /= top_val;
}

/**
 * mul - multiplies the second top element of the stack(or queue)
 * @top: Pointer to pointer to the top of the stack.
 * @line_number:Line number of the instruction.
 * Return:Void.
 */

void mul(stack_t **top, unsigned int line_number)
{
        int top_val;

        if ((*top) == NULL || (*top)->next == NULL)
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n",
                        line_number);
		free_stack(*top);
                exit(EXIT_FAILURE);
        }

	top_val = (*top)->n;
        delete_element(top, 0);
        (*top)->n *= top_val;
}
