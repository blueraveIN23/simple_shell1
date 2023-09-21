#include "shell.h"

/**
 * execve_main - main point
 *
 * Return: 0
 */

int execve_main(void)
{
	char cmd[MAX_CMD_LEN];

	while (1)
	{
		printf("$ ");
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			printf("\n");
			return (0);
		}

		cmd[strcspn(cmd, "\n")] = '\0';

		if (strlen(cmd) > 0)
		{
			pid_t pid = fork();

			if (pid < 0)
			{
				perror("fork");
				continue;
			}

			if (pid == 0)
			{
				execlp(cmd, cmd, NULL);

				perror("exec");
				exit(EXIT_FAILURE);
			}
			else
			{
				wait(NULL);
			}
		}
	}

	return (0);
}
