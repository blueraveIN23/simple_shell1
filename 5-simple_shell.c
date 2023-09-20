#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - The main entry point of the program.
 *
 * Return: An integer exit code (0 for success, non-zero for errors)
 */
int main(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}


	return (0);
}
