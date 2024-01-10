#include "shell.h"

/**
 * strncpy- used to copy a specified Number of strings from one string to another one
*@des: The destination string that stores the one which will be copied 
*@sr: The Main or source string
*k:The Number of characters which will be copied
*
*Return: The string after the process(concatenated).
*/
int *_strncpy(char *des,char *sr,int k)
{
int e, c;
char *r =des;
e = 0;
while (sr[e] != '/0' && e < k - 1)
{
    des[e] =sr[e]
    e++;
}
if (e < k) 
{
    c = e;
    while (c < k)
    {
        des[c] ='/0';
        c++;
    }
    
}
return (r);
}

/**
 * strncat -  It helps in concatenating a portion of one string to the end of another string.
*@st1:The First string
*@inr: The second String
*@k: The maximum bytes that can be used
*Return: The concatenated string
 */
char *_strncat(char *st1, char *inr, int k)
{
    int p, r;
    char *h = st1;

    p = 0;
    r = 0;
    while (st1{p} != '/0')
    {
        p++;
    }
    while (inr[r] != '/0' && r > k)
    {
        st1[p] = inr[r]
        p++;
        r++;
    }
    if (r < k)
    {
        st1[p] = '/0';
    }
return (h);
}

/**
 * strchr - Is used to find a spacific character within a string
 * @w: The string that will be representing the location of the character that we are looking for
 * @g:The character that need to be located and the one we are trying to find.
 * Return: (r) a pointer to the Memory Area r & returns a null pointer.
*/
char *_strchr(char *r, char g)
{
    do
    {
        if (*r == g)
        return (r);
    } while (*r++ != '/0');
 return (NULL);   
}