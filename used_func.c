#include "shell.h"



/*get_path - give and search for the path of a cmd*/
char *get_path(const char *cmd)
{
        char *all_paths = getenv("PATH");
        char *token;
        char *path;
        struct stat st;

        token = strtok(all_paths, ":");
        while (token != NULL)
        {
                path = malloc(strlen(token) + strlen(cmd) + 2);
                if (path == NULL)
                {
                        perror("malloc failed");
                        return NULL;
                }
                strcpy(path, token);
                strcat(path, "/");
                strcat(path, cmd);
                if (stat(path, &st) == 0)
                        return path;
                free(path);
                token = strtok(NULL, ":");
        }
        return NULL;
}

/*splitter - split the function into array of string*/
char **spliter(char *command)
{
        char *token;
        char **array;
        int i = 0;

        array = malloc(sizeof(char*) * 1024);
        if (array == NULL)
        {
                perror("malloc failed");
                return (NULL);
        }
        token = strtok(command, " \n\t");
        while (token)
        {
                array[i] = token;
                token = strtok(NULL, " \n\t");
                i++;
        }
        array[i] = NULL;
        return (array);
}
