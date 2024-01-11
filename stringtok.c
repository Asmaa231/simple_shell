#include "shell.h"
/**
 **string_token - function gets each path token
 *@command: input user comnd
 *@read_chars: number of comd characters
 *Return: path token
 */

char **string_token(char *command, int read_chars)
{
	char whole_cmd, *cp_cmd = NULL;
	const char *delim = " \n";
	char *tok;
	int toks_num = 0;
	char **argv;
	int i;

	cp_cmd = malloc(sizeof(char) * read_chars + 1);
	if (cp_cmd == Null)
		perror("memo allocation err");

	strcpy(cp_cmd, whole_cmd);
	toks_num = strtok(cp_cmd, delim);

	while (tok)
	{
		toks_num++;
		tok = strtok(0, delim);
	}
	toks_num++;
	argv = malloc(sizeof(char *) * (toks_num + 1));
	tok = strtok(cp_cmd, delim);
	for (i = 0; tok != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (_strlen(tok) + 1));
		_strcpy(argv[i], tok);
		tok = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(cp_cmd);
	free(command);
	return (argv);
}
