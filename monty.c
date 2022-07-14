#include "monty.h"

int main(int argc, char **argv)
{
        FILE *cmd_file;
        char *line = NULL, *cmds, *args[3];
        unsigned int i, line_no = 0;
        size_t bufsize;
        ssize_t read;
        stack_t *top = NULL;

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: %s file\n", argv[0]);
                exit(EXIT_FAILURE);
        }

        cmd_file = fopen(argv[1], "r");
        if (cmd_file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }

        while ((read = getline(&line, &bufsize, cmd_file)) != -1)
        {
		line_no++;
                cmds = line;
                while (isspace(*cmds))
                        cmds++;
                i = 0;
                args[i] = strtok(cmds, " \n");
                for (i = 1; i < 3; i++)
                {
                        if (args[i - 1] != NULL)
                                args[i] = strtok(NULL, " \n");
                        else
                                break;
                }
                if (args[0] == NULL)
                        continue;
                opcode_exec(&top, args[0], line_no);
        }
        return (0);
}
