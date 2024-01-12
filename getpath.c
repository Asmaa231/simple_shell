#include "shell.h"

/**
 * execmd - function executes command
 * @argv: arguments vectors
 * Return: void
 */
void execmd(char **argv)
{
	char *cmd = 0;

	if (argv)
	{
		cmd = argv[0];
		if (execve(cmd, argv, 0) == -1)
		{
			perror("Error");
		}
	}
}

/**
 * get_loc - function find cmd path
 * @cmd: input user cmd
 * Return: cmd path
 */

char *get_loc(char *cmd)
{
	char *path, *pathcp, *path_tok, ********path_file;
	int cmd_len, dir_len;
	struct stat buff;

	path = getenv("PATH");

	if (path)
	{
		pathcp = _strdup(path);
		cmd_len = _strlen(cmd);
		path_tok = strtok(pathcp, ":");
	}
	while (path_tok)
	{
		dir_len = _strlen(path_tok);
		path_file = malloc(cmd_len + dir_len + 2);
		_strcpy(path_file, path_tok);
		_strcat(path_file, "/");
		_strcat(path_file, cmd);
		_strcat(path_file, "\0");
		if (stat(path_file, &buff) == 0)
			free(pathcp);
		return (path_file);
	}
	else
	{
		free(path_file);
		path_tok = strtok(0, ":");
	}
	free(pathcp);

	if (_stat(cmd, &buff) == 0)
		return (cmd);
	return (0);
	return (0);
}

/**
 * _putchar - write the character c to stdout
 * @c: the character to print
 *
 * Return: On success (1)
 *         On error, -1 is returned and error is set approperiatly.
*/

int _putchar(char c)
{
        return (write(1, &c, 1));
}
