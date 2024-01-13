#include "shell.h"
/**
*_strncpy- copy a specified Number of strings
*@des: The destination string stores the one will be copied 
*@sr: The Main or source string
*k:The Number of characters which will be copied
*
*Return: The string after the process(concatenated).
*/
int *_strncpy (char *des,char *sr,int k)
 {
int e, c;
char *r =des;
e = 0;
<<<<<<< HEAD
while (sr[e] != '\0' && e < k - 1)
=======
while (sr[e] != '\0' && e < k)
>>>>>>> 3393086c3846d7aa28d1deb7acf8559fd9e28c64
{
des[e] = sr[e];
e++;
}
if (e < k) 
{
c = e;
while (c < k)
{
des[c] ='\0';
c++;
}
}
return (r);
}

/**
*_strncat - concatenating a portion of one string to the end of another string.
*@st1:The First string
*@inr: The second String
*@k: The maximum bytes that can be used
*Return: The concatenated string
*/
char *_strncat (char *st1, char *inr, int k)
{
int p, r;
char *h = st1;
p = 0;
r = 0;
while (st1[p] != '\0')
{
p++;
}
<<<<<<< HEAD
    while (inr[r] != '\0' && r > k)
=======
    while (inr[r] != '\0' && r < k)
>>>>>>> 3393086c3846d7aa28d1deb7acf8559fd9e28c64
{
st1[p] = inr[r];
p++;
r++;
}
if (r < k)
{
st1[p] = '\0';
}
return (h);
}

/**
 *_strchr - Is used to find a spacific character within a string
 * @w: The string that will be representing the location of the character that we are looking for
 * @g:The character that need to be located and the one we are trying to find.
 * Return: (r) a pointer to the Memory Area r & returns a null pointer.
*/
char *_strchr(char *w, char g)
{
do{
<<<<<<< HEAD
        if (*r == g)
        return (r);
    } while (*r++ != '\0');
=======
        if (*w == g)
        return (w);
     while (*w++ != '\0');
>>>>>>> 3393086c3846d7aa28d1deb7acf8559fd9e28c64
 return (NULL);   
}