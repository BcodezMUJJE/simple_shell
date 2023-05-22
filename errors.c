#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be displayed
 *
 * Return: Null
 */
void _eputs(char *str)
{
int i = 0;

if (!str)
return;

while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}

/**
 * _eputchar - writes the character 'c' to stderr
 * @c: Character to print
 *
 * Return: 1 on success
 * -1 on error, and errno is set appropriately.
 */
int _eputchar(char c)
{
static int i = 0;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}

if (c != BUF_FLUSH)
buf[i++] = c;

return (1);
}

/**
 * _putfd - writes the character 'c' to the given file descriptor
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: 1 on success
 * -1 on error, and errno is set accordingly.
 */
int _putfd(char c, int fd)
{
static int i = 0;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}

if (c != BUF_FLUSH)
buf[i++] = c;

return (1);
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: file descriptor to write to
 *
 * Return: number of characters written
 */
int _putsfd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);

while (*str)
{
i += _putfd(*str++, fd);
}

return (i);
}
