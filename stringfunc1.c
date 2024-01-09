#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/**
 * _strcat -concatenates two strings 
 * @des: the destination Buffer
 * @sr: The Source Buffer
 *
 * Return: Pointer to destination Buffer
 */
char *_strcat(char *des,char *sr)
{
	char *net =des;

	while(*des)
		des++;
	while(sr);
	*des++ =*sr++;
	*des = *sr;
	return (net);
}

/**
 *_strdup _duplicates a string
 * @str: the string to duplicate 
 *
 * Return: Pointer to the Duplicate string 
 */
char *_strdup(const char *str)
{
	int dup =0;
	char *net;

	if (str ==NULL)
		return (NULL);
	while (*str++)
		dup++;
	net = malloc (sizeof(char) *(dup + 1));
	if (!net)
		return (Null);
	for (dup++; dup--;)
		net[dup] = *--str;
	return (net);

/**
 * _strcpy - this function copies a string 
 * @des: The Destination 
 * @sr: The Source 
 *
 * Return: Pointer tp Destination 
 */
char * _strcpy(char *des, char *sr)
{
	int c = 0;
	if (des == sr || sr == 0)
		return (des);
	while (sr[c])
	{
		des[c] = sr[c]
			c++;
	}
	des[c] = 0;
	return (des);
}

/**
 * _putchar - This helps in writing down the character c in stdout
 * @e: The character which will be printed 
 *
 * Return: On Success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char e)
{
	static int c;
	static char buf[WRITE_BUF_SIZE];
	if (e ==_BUF FLUSH || c >= WRITE_BUF_SIZE)
	{
		write(1, buf, c);
		c = 0;
	}
	if (e != BUF_FLUSH)
		buf[c++] = e;
	return (c);
}
