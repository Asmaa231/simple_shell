#include "shell.h"

int main(int ac, char **argv)
{
	char *prom = "(Eshell)$";
	ssize_t n = 0;
	char *whole_cmd, *cp_cmd = 0;
	ssize_t read_chars;
	const char *delim = " \n";
	char *tok;
	int toks_num = 0;
	int i;

	while (1)
	{
		printf("%s", prom);
		read_chars = getline(&whole_cmd, &n, stdin);
		if (read_chars == -1)
		{
			printf("exit shell\n");
			return (-1);
		}

		cp_cmd = malloc(sizeof(char) * read_chars);
		if (cp_cmd == 0)
		{
			perror("memo allocation err");
			return (-1);
		}
		strcpy(cp_cmd, whole_cmd);
		toks_num = strtok(cp_cmd, delim);

		while (tok)
		{
			toks_num++;
			tok = strtok(0, delim);
		}
		toks_num++;
		argv = malloc(sizeof(char *) * toks_num);
		tok = strtok(cp_cmd, delim);
		for (i = 0; tok != '\0'; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(tok));
			_strcpy(argv[i], tok);
			tok = strtok(0, delim);
		}
		argv[i] = '\0';

		execmd(argv);
		free(argv);
		free(whole_cmd);
		free(cp_cmd);
	}
	return (0);
}
