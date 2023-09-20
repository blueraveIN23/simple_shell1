#include "shell.h"

/**
 * exit_shell - Exits the shell program.
 *
 */
void exit_shell(void)
{
	printf("\n");
	exit(0);
}

/**
 * exit_ main - Is the main function for the simple shell program.
 *
 * Return: Return 0 when the shell exits successfully.
 */
int exit_main(void)
{
	char cmd[MAX_CMD_LEN];

	while (1)
	{
		printf(PROMPT);

		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			printf("\n");
			exit_shell();
		}
		cmd[strlen(cmd) - 1] = '\0';

		if (strcmp(cmd, "exit") == 0)
		{
			exit_shell();
		}
		if (fork() == 0)
		{
			execlp(cmd, cmd, NULL);
			perror(cmd);
			exit(1);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
