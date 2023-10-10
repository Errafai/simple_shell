#ifndef MAIN_H
#define MAIN_H


char *_command(const char *cmd);
char * _getenv(char *env);

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

size_t _getline(char **line, size_t *n, int fd);


#endif

