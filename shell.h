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
#include <ctype.h>
#include <stdbool.h>


#define Delim
extern char environ;

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
        list_t *env;
} info_t;


/**
 * struct builtin: has buildin str and other func
 * @kind: bulitin comd flag
 * @fun: It's a function
 */
typedef struct builtin
{
        char *kind;
        int (*fun)(info_t *);
} builtin_t;

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
} list_t;


void sigintHandler(__attribute__((unused))int sined_num);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int _getline(info_t *info, char **poter, size_t *lenth);
void execmd(char **argv);


char *get_loc(char *cmd);
int *_stat(const char *pathnm, struct stat **statbuff);


char *getenv(const char *name);
int *_setenv(const char *name, const char *value, int overwrite);
int *_unsetenv(const char *name);

char *strtok(char *s, const char *delim);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(const char *s);
int *_strcmp(char *s1, char *s2);
int *_strlen(char *s);

int _putchar(char c);

#endif
