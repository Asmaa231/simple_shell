#include "shell.h"
/**
 **string_token - function gets each path token
 *@command: input user comnd
 *@read_chars: number of comd characters
 *Return: path token
 */

char **string_token(char *command, int read_chars)
{
	char *cp_cmd = NULL;
	const char *delim = " ";
	char *tok, **argv;
	int toks_num = 0, i;

	cp_cmd = malloc(sizeof(char) * read_chars + 1);
	if (cp_cmd == NULL)
	{
		perror("memo allocation err");
		exit(EXIT_FAILURE);
	}
	strcpy(cp_cmd, command);
	tok = strtok(cp_cmd, delim);
	while (tok)
	{
		toks_num++;
		tok = strtok(NULL, delim);
	}
	toks_num++;
	argv = malloc(sizeof(char) * toks_num);
	if (argv == NULL)
	{
		perror("memory allocation error");
		exit(EXIT_FAILURE);
	}
	tok = strtok(command, delim);
	for (i = 0; tok != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (strlen(tok) + 1));
		if (argv[i] == NULL)
		{
			perror("memory allocation error");
			exit(EXIT_FAILURE);
		}
		_strcpy(argv[i], tok);
		tok = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(cp_cmd);
	return (argv);
}
