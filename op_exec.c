#include "monty.h"

void opcode_exec(stack_t **top, char *command, unsigned int line_number)
{
	int i;
	instruction_t opcodes[10];
	char *mnemonics[] = {"push", "pall"};
	void (*func[])(stack_t **, unsigned int) = {push, pall};
	extern int data_num;

	for (i = 0; i < 2; i++)
	{
		opcodes[i].opcode = mnemonics[i];
		opcodes[i].f = func[i];
	}
	for (i = 0; i < 10; i++)
	{
		if (strcmp(opcodes[i].opcode,command) == 0)
			break;
	}
	if (i == 10)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, command);
		exit(EXIT_FAILURE);
	}
	opcodes[i].f(top, line_number);
}
