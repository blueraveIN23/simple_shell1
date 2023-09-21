#include "shell.h"

/**
 * _getpath - returns the path of a command
 * @argv: number of argument passed
 *
 * Return: 0
 */

int _getpath(char **argv)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char cmd[1024];
	int found = 0;

	while (token != NULL)
	{
		snprintf(cmd, sizeof(cmd), "%s/%s", token, argv[1]);
		if (access(cmd, X_OK) == 0)
		{
			found = 1;
			break;
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);

	if (found)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			execv(cmd, argv + 1);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		printf("%s: command not found\n", argv[1]);
	}

	return (0);
}
