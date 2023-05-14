#include "shell.h"

/**
* interactive –it returns true when shell is interactive mode
* @info: address of struct
*
* Return: 1 if interactive mode, 0 if not
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim –it check if character is a delimeter
* @c: the char to check
* @delim: the string delimeter
* Return: 1 if true, 0 when false
*/
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
* _isalpha –it checks for alphabet characters
* @c:  character to input
* return: 1 if c is alphabetic, 0 if not
*/
int _isalpha(int c)
{
if ((c >= ‘a’ && c <= ‘z’) || (c >= ‘A’ && c <= ‘Z’))
return (1);
else
return (0);
}

/**
* _atoi – converts string to integer
* @s: string to be converted
* Return: 0 if there's no number in string, converted number if there is
*/
int _atoi(char *s)
{
int I, sign = 1, flag = 0, output;
unsigned int result = 0;

for (I = 0; s[i] != ‘\0’ && flag != 2; i++)
{
if (s[i] == ‘-‘)
sign *= -1;

if (s[i] >= ‘0’ && s[i] <= ‘9’)
{
flag = 1;
result *= 10;
result += (s[i] – ‘0’);
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}
