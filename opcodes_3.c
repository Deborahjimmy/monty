#include "monty.h"
unsigned int mode;

/**
 *stack - sets the format of the data to a stack (LIFO)
 *@top: Pointer to pointer to the top of the stack.
 *@line_number:Line number of the instruction.
 *Return:Void.
 */

void stack(stack_t **top __attribute__((unused)),
	   unsigned int line_number __attribute__((unused)))
{
	mode = 0;
}

/**
 *Queue - sets the format of the data to a queue (FIFO)
 *@top: Pointer to pointer to the top of the stack.
 *@line_number:Line number of the instruction.
 *Return:Void.
 */

void queue(stack_t **top __attribute__((unused)),
	   unsigned int line_number __attribute__((unused)))
{
	mode = 1;
}
