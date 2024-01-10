#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#include <math.h>
#include <ctypes.h>

=======
#include <canio.h>
#include <stdbool.h>
#include <math.h>

#define Delim 
extern char environ;

// getline.c
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void execmd(char **argv);

//getpath.c
char *get-loc(char *cmd);  // get path location
int *stat(const char *pathnm, struct stat **statbuff);  //check if file path exists or not

//env.c
char *getenv(const char *name);   // get path envir. name
int *_setenv(const char *name, const char *value, int overwrite);   // change path envir. name
int *_unsetenv(const char *name);  //delete path envir. name

//str.c
char *strtok(char *s, const char *delim);  // split string
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(const char *s);
int *_strcmp(char *s1, char *s2);
int *_strlen(char *s); 

//struct
/**
 * struct infopass: has false arguments
 * @arg: arguments of string got by getline
 * @argv: array of string
 * @argc: number of argument
 * @environ: a copy of environ
 * @path: str path of cmd
 * @envchange: on if changing environ
 * @env: linked list of environ copy
 * @error_num: exit() error code
 * @filename: a program name
 */
typedef struct infopass
{
    char *arg;
    char **argv;
    char **environ;
    char *path;
    char *filename;
    int argc;
    int envchange;
    list-t env;
}list_t


/**
 * struct builtin: has buildin str and other func
 * @kind: bulitin comd flag
 * @fun: It's a function
 */
typedef struct builtin
{
    char *kind;
    int (fun *)(info_t *);
}builtin_t


/**
 * struct strlist: the linked list
 * @str: the string
 * @num: field number
 * @nxt: next node pointer
 */
typedef struct strlist
{
    char *str;
    int num;
    struct strlist *nxt;
}list_t

#endif