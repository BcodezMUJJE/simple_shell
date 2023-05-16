#include "shell.h"

/**
**_strncpy – copies a string pointer
*@dest: destination string to be copied to
*@src: source of string
*@n: number of characters to be copied
*Return: concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
int I, j;
char *s = dest;

i = 0;
while (src[i] != ‘\0’ && I < n – 1)
{
dest[i] = src[i];
i++;
}
if (I < n)
{
j = I;
while (j < n)
{
dest[j] = ‘\0’;
j++;
}
}
return (s);
}

/**
**_strncat – concatenates two strings
*@dest: the first string
*@src: the second string
*@n: the amount of bytes to be maximally used
*Return: the concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
int I, j;
char *s = dest;

i = 0;
j = 0;
while (dest[i] != ‘\0’)
i++;
while (src[j] != ‘\0’ && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}

/**
**_strchr – finds a character in a string
*@s: string to be parsed
*@c: character to search
*Return: (s) a pointer to the memory area s
*/
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');

return (0);
}