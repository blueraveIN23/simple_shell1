#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

#define MAX_ARGS 64
#define PROMPT "simple-shell$"
#define MAX_CMD_LEN 256


int main(void);
int check_betty(void);
int main_arg(int argc, char *argv[]);
char *search_path(char *cmd);
int main_path(void);
void execute_cmd(char *full_path, char **args);
void tokenize_cmd(char *cmd, char **args);

void execute_command(char** argv);
char **tokenize_command(char* cmd, char** argv);
char* read_comd(char *cmd);
void print_prompt(void);
char *token;
extern char **environ;
int exit_main(void);
void exit_shell(void);
int execve_main(void);
void handle_exit(char *arg);

int _getpath(char **argv);


extern char **environ;

/*********************** CUSTOM DEFFINITIONS ********************************/

char *d3s(char *str);
char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);
char **str2arr(char *str, char *delim);
size_t _strlen(char *str);
void free_dp(char **arr);

/*********************** GETLINE ******************************************/

char *my_getline(void);
#endif
