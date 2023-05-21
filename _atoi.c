#include <stdlib.h>
#include "shell.h"

int interactive(ino_t *ino);

/**
* is_delim –it check if characteris a delimeter
* @c: the char to check
* @delim: the string delimeter
* Return: 1 if true, 0 when false
*/
int interactive(ino_t *ino);
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
* _isalpha –it checks for alphabetcharacters
* @c: character to input
* return: 1 if c is alphabetic, 0 if not
*/
int _isalpha(int c)
{
if ((c >= 'a' && c<= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
* _atoi – converts string tointeger
* @s: string to be converted
* return: 0 if there's no numberin string, converted number if there is
*/
int _atoi(char *s)
{
int I, sign = 1, flag = 0, output;
unsigned int result = 0;

for (I = 0; s[I] != '\0' && flag != 2; I++)
{
if (s[I] == '-')
sign *= -1;

if (s[I] >= '0' && s[I]<= '9')
{
flag = 1;
result *= 10;
result += (s[I] - '0');
}
else if (flag == 1)
flag = 2;
}        if (sign == -1)
output = -result;
else
output = result;

return (output);
}

/**
* interactive –it returns truewhen shell is interactive mode
* @info: address of struct
*
* Return: 1 if interactive mode, 0 if not
*/
int interactive(ino_t *ino)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
