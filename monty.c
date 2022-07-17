#include "monty.h"

/**
 * main - Entry point of the program.
 * @argc: Number of arguments to the program.
 * @argv: Pointer to string arguments.
 * Return: Always 0.
*/
int main(int argc, char **argv)
{
	FILE *cmd_file;
	char *line = NULL, *cmds, *args[3];
	unsigned int i, line_no = 0;
	size_t bufsize = 0;
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	cmd_file = fopen(argv[1], "r");
	if (cmd_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack(NULL, 0);
	while ((getline(&line, &bufsize, cmd_file)) != -1)
	{
		line_no++;
		cmds = line;
		while (isspace(*cmds))
			cmds++;
		i = 0;
		args[i] = strtok(cmds, " \n");
		for (i = 1; i < 3; i++)
			if (args[i - 1] != NULL)
				args[i] = strtok(NULL, " \n");

		if (args[0] == NULL || (*args[0]) == '#')
			continue;
		argument = args[1];
		opcode_exec(&top, args[0], line_no);
	}
	fclose(cmd_file);
	free_stack(top);
	free(line);
	line = NULL;
	return (0);
}
