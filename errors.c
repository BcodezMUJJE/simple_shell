#include "shell.h"

/**
* _eputs –this prints an input string
* @str: the string to be displayed
*
* Return: Null
*/
void _eputs(char *str)
{
int I = 0;

if (!str)
return;
while (str[i] != ‘\0’)
{
_eputchar(str[i]);
i++;
}
}

/**
* _eputchar – writes the alphabet c to stderr
* @c: Character to print
*
* Return: 1 on success
* -1 on error,is returned, and errno is set appropriately.
*/
int _eputchar(char c)
{
static int I;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || I >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
* _putfd – writes the c alphabet to given fd
* @c: The character to print
* @fd: The filedescriptor to write to
*
* Return: 1 on success
* -1 is returned on error, and errno is set accordingly.
*/
int _putfd(char c, int fd)
{
static int I;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || I >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
* _putsfd – prints an input string
* @str: the string to be printed
* @fd: the filedescriptor written to
*
* Return: number of chars put
*/
int _putsfd(char *str, int fd)
{
int I = 0;

if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}
