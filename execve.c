#include "shell.h"

/**
 * main - main point
 *
 * Return: 0
 */

int main(void)
{
	int i;
	char cmd[MAX_CMD_LEN];
	char *args[MAX_ARGS];
	char *token;
	int status;
	pid_t pid;

	while (1)
	{
		printf("$ ");
		if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)
			break;
		cmd[strlen(cmd)- 1] = '\0';
		token = strtok(cmd, " ");

		for (i = 0; token != NULL; i++)
		{
			args[i] = token;
			token = strtok(NULL, " ");
		}
		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				perror("Error");
			exit(0);
		}
		else if(pid > 0)
			wait(&status);
	}
	return (0);
}
