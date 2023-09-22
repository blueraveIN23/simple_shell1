#include "shell.h"

/**
 * handle_exit - function that handles the exit in built in command
 * @arg: argument
 *
 * Return: 0
 */

void handle_exit(char *arg)
{
	int status;

	if (arg == NULL)
	{
		printf("Exiting with status 0\n");
		exit(0);
	}

	status = atoi(arg);

	if (status == 0 && arg[0] != '0')
	{
		printf("exit: Numeric argument required.\n");
	}
	else
	{
		printf("Exiting with status %d\n", status);
		exit(status);
	}
}
