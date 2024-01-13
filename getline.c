#include "shell.h"

/**
 * input_buf - function is designed to buffer chained commands.
 * @info: It takes info as a parameter struct
 * @buf: This function takes buf as the address of buffer
 * @sen: address of sen var
 *
 * Return: An integer Number that could be read in bytes
 */
ssize_t input_buf(info_t *info, char **buf, size_t *sen)
{
	ssize_t g = 0;
	size_t sen_p = 0;

	if (!*sen) /* if there is nothing left in the buffer, then fill it */
	{
		/* buffer free bfree((void **)info->cmd_buf); Memory*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		g = getline(buf, &sen_p, stdin);
#else
		g = _getline(info, buf, &sen_p);
#endif
		if (g > 0)
		{
			if ((*buf)[g - 1] == '\n')
			{
				(*buf)[g - 1] = '\0'; /* remove trailing newline character /n */
				g--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is it a buffer chained command ? */
			{
				*sen = g;
				info->cmd_buf = buf;
			}
		}
	}
	return (g);
}

/**
 * get_input - reading a line from a file or another source with execluding the newline character '/n'
 * @intel: parameter struct used  to read input data, possibly from a file or another source.
 *
 * Return: Number in bytes to be read
 */
ssize_t get_input(info_t *intel)
{
	static char *buf; /* the symbol ';' command chain buffer */
	static size_t i, u, len;
	ssize_t g = 0;
	char **buf_pt = &(intel->arg), *p;

	_putchar(BUF_FLUSH);
	g = input_buf(intel, &buf, &len);
	if (g == -1) /* EOF */
		return (-1);
	if (len)	/* there are still commands left in the chain buffer */
	{
		u = i; /* initialize a new iterator to current buffer position */
		p = buf + i; /* get pointer for return */

		check_chain(intel, buf, &u, i, len);
		while (u < len) /* iterate to the semicolon or go to end */
		{
			if (is_chain(info, buf, &u))
				break;
			u++;
		}

		i = u + 1; /* increment nulled ';'' */
		if (i >= len) /* you have reached the end of the buffer? */
		{
			i = len = 0; /* will reset the position and length for it */
			intel->cmd_buf_type = CMD_NORM;
		}

		*buf_pt = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command(buffer) */
	}

	*buf_pt = buf; /* else not a chain, pass back buffer from _getline() */
	return (g); /* return length of buffer from _getline()command */
}

/**
 * read_buf - reading from a file descriptor into a buffer,and handling file management.
 * @info: parameter struct which is having inforamtion regarding the reading process
 * @buf: a pointer buffer where the data will be read from
 * @k: a size variable that holds the size of the buffer pointed to
 *
 * Return: o
 */
ssize_t read_buf(info_t *info, char *buf, size_t *k)
{
	ssize_t o = 0;

	if (*k)
		return (0);
	o = read(info->readfd, buf, READ_BUF_SIZE);
	if (o >= 0)
		*k = o;
	return (o);
}

/**
 * _getline - is used to read an entire line from a stream, such as the standard input stream stdin, and store it in a buffer
 * @info: parameter struct that holds configuration or context information related to the input operation
 * @poter: the address of pointer to buffer, preallocated or NULL
 * @lenth:  the size of preallocated pointer buffer if it is not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **poter, size_t *lenth)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t g;
	ssize_t t = 0, s = 0;
	char *p = NULL, *new_pt = NULL, *y;

	p = *poter;
	if (p && lenth)
		s = *lenth;
	if (i == len)
		i = len = 0;

	t = read_buf(info, buf, &len);
	if (t == -1 || (t == 0 && len == 0))
		return (-1);

	y = _strchr(buf + i, '\n');
	g = y ? 1 + (unsigned int)(y - buf) : len;
	new_pt = _realloc(p, s, s ? s + g : g + 1);
	if (!new_pt) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_pt, buf + i, g - i);
	else
		_strncpy(new_pt, buf + i, g - i + 1);

	s += g - i;
	i = g;
	p = new_pt;

	if (lenth)
		*lenth = s;
	*poter = p;
	return (s);
}

/**
 * sigintHandler - Cannot be terminated using Ctrl+C
 * @sined_num: This refers to the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sined_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
