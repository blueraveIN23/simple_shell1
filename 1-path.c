#include "shell.h"

/**
 * search_path - program that handles path
 * @cmd: command directory
 *
 * Return: 0
 */

char *search_path(char *cmd)
{
	char *path, *path_copy, *dir, *full_path;
	int cmd_len, dir_len;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	cmd_len = strlen(cmd);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		dir_len = strlen(dir);
		full_path = malloc(dir_len + cmd_len + 2);
		if (full_path == NULL)
			return (NULL);

		strcpy(full_path, dir);
		full_path[dir_len] = '/';
		strcpy(full_path + dir_len + 1, cmd);

		if (access(full_path, X_OK) == 0)
			break;
		free(full_path);
		full_path = NULL;
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (full_path);
}
/**
 * tokenize_cmd - Tokenize a command line intro arguments
 * @cmd: the command line to tokenize
 * @args: An array of pointers to store the arguments
 */
void tokenize_cmd(char *cmd, char **args)
{
	int i;
	char *token;

	token = strtok(cmd, " ");
	for (i = 0; token != NULL; i++)
	{
		args[i] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
/**
 * execute_cmd - Execute a command
 * @full_path: The full path to the executable
 * @args: The arguments to pass to the executable
 */

void execute_cmd(char *full_path, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(full_path, args, NULL) == -1)
			perror("Error");
		exit(0);
	}
	else if (pid > 0)
		wait(&status);
}
/**
 * main_path - main code
 * Return: 0
 */

int main_path(void)
{
	char cmd[MAX_CMD_LEN];
	char *args[MAX_ARGS];
	char *full_path;

	while (1)
	{
		printf("$ ");
		if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)
			break;
		cmd[strlen(cmd) - 1] = '\0';

		tokenize_cmd(cmd, args);

		full_path = search_path(args[0]);
		if (full_path != NULL)
		{
			execute_cmd(full_path, args);
			free(full_path);
		}
		else
			printf("%s: command not found\n", args[0]);
	}
	return (0);
}
