#include "shell.h"

/**
 * print_prompt - print out the promt message for input
 *
 * Return: 0
 */

void print_prompt(void)
{
	printf("$ ");
}

/**
 * read_comd - function that reads the command
 * @cmd: command to read
 * Return: cmd
 */

char* read_comd(char *cmd)
{
	if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)
	{
		printf("\n");
		exit(0);
	}
	cmd[strlen(cmd) - 1] = '\0';
	return (cmd);
}
/**
 * tokenize_command - function that tokenize the command written
 * @cmd: command to be tokenized
 * @argv: number of arguments passed
 * Return: argument
 */

char **tokenize_command(char *cmd, char **argv)
{
	int i;
	char *token = strtok(cmd, " ");

	for (i = 0; i < MAX_ARGS - 1 && token != NULL; i++)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
	}
	argv[MAX_ARGS - 1] = NULL;
	return (argv);
}
/**
 * execute_command - function that executes command written
 * @argv: number of argument passed
 * Return: 0
 */

void execute_command(char **argv)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		perror("Exec failed");
		exit(1);
	}
	else
	{
		int status;

		wait(&status);
	}
}

/**
 * execve_main - main point
 *
 * Return: 0
 */

int execve_main(void)
{
	char cmd[MAX_CMD_LEN];
	char *argv[MAX_ARGS];

	while (1)
	{
		print_prompt();
		read_comd(cmd);
		tokenize_command(cmd, argv);
		execute_command(argv);
	}

	return (0);
}
