#include "shell.h"

/**
* main - Entry point
* @ac: number of arguments
* @argv: pointer to arrays of pointers
* Return: 0
*/

int main(int ac, char **argv)
{
	char *prom = "(Eshell)$";
	size_t n = 0;
	char *whole_cmd = NULL;
	ssize_t read_chars;
	char **toks;

	(void)argv;
	(void)ac;

	while (1)
	{
		printf("%s", prom);
		read_chars = getline(&whole_cmd, &n, stdin);
		if (read_chars == -1)
		{
			return (-1);
		}
		toks = string_token(whole_cmd, read_chars);
		execmd(toks);
	}
	free(whole_cmd);
	return (0);
}
