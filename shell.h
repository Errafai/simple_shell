#ifndef MAIN_H
#define MAIN_H



extern char **environ;


#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stddef.h>

/*******built in function*******/
int built_in(char *command);
void handle_builtin(char **command,char **argv, int *status, int idx);
void exit_shell(char **command, int *status);
void print_env(char **command, int *status);



/******principal functions*******/
void printerror(char *name, char *cmd, int idx);
char *_getpath(char *command);
char *_getenv(char *name);
int _execute(char **command, char **argv, int idx);
char **tokniser(char *line);
void free_array(char **array);
char *read_line(void);
char *_itoa(int n);
void reverse_string(char *str, int len);

#define DELIME " \t\n"
#endif

