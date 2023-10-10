#ifndef MAIN_H
#define MAIN_H

/*all used library*/
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stddef.h>

/*envirmont variable*/
extern char **environ;

/*used functions*/
char **spliter(char *command);
char *get_path(const char *cmd);

#define INUSED(X) (void)(X)
#endif

