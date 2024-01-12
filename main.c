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
	char **toks;
	int i;

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
