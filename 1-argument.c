#include "shell.h"

/**
 * main_arg - program that handles command line arguments
 * @argc: number of arguments passed
 * @argv: name of the program itself
 *
 * Return: 0
 */

int main_arg(int argc, char *argv[])
{
	int i;

	printf("the program name is: %s\n", argv[0]);
	printf("the number of arguments passed is: %d\n", argc - 1);
	printf("the arguments are:\n");
	for (i = 1; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
