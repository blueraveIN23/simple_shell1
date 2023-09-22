#include "shell.h"

/**
 * main - Main entry to the program.
 *
 * Return: 0 if successful.
 */
int arg_main(void)
{
	char cmd[MAX_CMD_LEN];
	char *args[MAX_ARGS];
	int arg_count;
	char *pos;
	int i;

	printf("SimpleShell> ");
	while (fgets(cmd, sizeof(cmd), stdin) != NULL)
	{
		arg_count = 0;

		memset(args, 0, sizeof(args));

		while ((pos = strchr(cmd, ' ')) != NULL)
		{
			args[arg_count++] = strndup(cmd, pos - cmd);


			memmove(cmd, pos + 1, strlen(pos));
			arg_count++;
		}
		args[arg_count++] = strndup(cmd, strlen(cmd) - 1);
		arg_count++;
		args[arg_count] = NULL;

		for (i = 0; i < arg_count; i++)
		{
			free(args[i]);
		}

		printf("SimpleShell> ");
	}

	return (0);
}
