#include "shell.h"
#include <stdio.h>

#define MAX_INPUT_SIZE 1024

/**
 * execute_command - Executes a coomand with no arguments.
 * 
 */
void execute_command(void);

{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		perror("fork");
	}
	else
	{
		{
		       wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * main - Main function of the simple shell program.
 * 
 * Return: Return an integer status code on completion.
 */
int main(void);

{
	char *token;
	char input[MAX_INPUT_SIZE];
	int should_run = 1;

	while (should_run)
	{
		printf("Simple Shell> ");
		fflush(stdout);

		fgets(input, MAX_INPUT_SIZE, stdin);

		input[strlen(input) - 1] = '\0';

		char *token;
		int i = 0;
		char *args[64];

		while ((token = strtok(i == 0 ? input : NULL, " ")) != NULL)
		{
			args[i] = token;
			i++;
		}
		args[i] = NULL;

		if (i > 0)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				should_run = 0;
				printf("Exiting the shell.\n");
			}
			else
			{
				execute_command(args);
			}
		}
	}
	return (0);
}
