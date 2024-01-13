#include "shell.h"

/**
 *_strlen - retuns the length of a string
 *@e: the string which will be checked 
 *
 * Retrun: integer length of the string
 */
int _strlen(char *e)
{
	int c= 0;

	if(!e)
		return (0); 

	while (*e != '\0')
		c++;
		e++;
	return (c);
}
/**
 * _strcmp- performs to compare between two null terminated strings leographically
 *@c1: The first string
 *@c2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2,  Zero if s1 == s2 
 */
int _strcmp(char *c1 , char *c2)
{
	while (*c1 && *c2)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
if (*c1 == *c2)
	return(0);
else
	return (*c1 < *c2 ? -1 : 1);
}

/**
 * _starts with - checks if the Needle starts with a haystack
 * @haystack: A string to look or search
 * @needle: The Substring that needs to be found 
 *
 * Return: address of next char of haystack or Null
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if(*needle++ != *haystack++)
			return (NULL);
	return ((char*)haystack);
}
