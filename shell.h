#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

int main(void);
int check_betty(void);
int main_arg(int argc, char *argv[]);
char *search_path(char *cmd);
int main_path(void);
void execute_cmd(char *full_path, char **args);
void tokenize_cmd(char *cmd, char **args);
void execute_command(void);
char *token;


#endif
