#include "monty.h"

/**
 * opcode_exec - executes the opcode functions.
 * @top: Pointer to pointer to top of the stack (or queue).
 * @command: Opcode to be executed.
 * @line_number: Line number of the command.
 * Return: Void.
*/
void opcode_exec(stack_t **top, char *command, unsigned int line_number)
{
	int i;
	instruction_t opcodes[17];
	char *mnemonics[] = {"push", "pall", "pint", "pop", "swap", "add", "nop",
			     "sub", "div", "mul", "mod", "pchar", "pstr",
			     "rotl", "rotr", "stack", "queue"};
	void (*func[])(stack_t **, unsigned int) = {push, pall, pint, pop, swap,
						    add, nop, sub, divd, mul,
						    mod, pchar, pstr, rotl,
						    rotr, stack, queue};

	for (i = 0; i < 17; i++)
	{
		opcodes[i].opcode = mnemonics[i];
		opcodes[i].f = func[i];
	}
	for (i = 0; i < 17; i++)
	{
		if (strcmp(opcodes[i].opcode, command) == 0)
			break;
	}
	if (i == 17)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, command);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	opcodes[i].f(top, line_number);
}
