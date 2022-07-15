#include "monty.h"

unsigned int mode;

void stack(stack_t **top __attribute__((unused)),
	   unsigned int line_number __attribute__((unused)))
{
	mode = 0;
}

void queue(stack_t **top __attribute__((unused)),
	   unsigned int line_number __attribute__((unused)))
{
	mode = 1;
}
