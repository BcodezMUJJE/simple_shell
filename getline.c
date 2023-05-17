#include "shell.h"

/**
 * input_buf - function that takes in an info_t struct and two pointers to
 * char arrays and assigns them values
 *
 * @info: pointer to info_t struct
 * @buf: pointer to pointer to char array
 * @len: pointer to size_t variable
 *
 * Return: ssize_t value
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t r = 0;
size_t len_p = 0;

if (!*len) /* if nothing left in the buffer, fill it */
{
/*bfree((void **)info->cmd_buf);*/
free(*buf);
*buf = 0;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
r = getline(buf, &len_p, stdin);
#else
r = _getline(info, buf, &len_p);
#endif
if (r > 0)
{
if ((*buf)[r – 1] == ‘\n’)
{
(*buf)[r – 1] = ‘\0’; /* removes trailing newlines */
r--;
}
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
/* if (_strchr(*buf, ‘;’)) is this a command chain? */
{
*len = r;
info->cmd_buf = buf;
}
}
}
return (r);
}

/**
* get_input – function gets a line minus the newline
* @info: parameter info_t struct
*
* Return: bytes read
*/
ssize_t get_input(info_t *info)
{
static char *buf; /* the ‘;’ command chain buffer */
static size_t I, j, len;
ssize_t r = 0;
char **buf_p = &(info->arg), *p;

_putchar(BUF_FLUSH);
r = input_buf(info, &buf, &len);
if (r == -1) /* EOF */
return (-1);
if (len) /* there are commands left in the chain buffer */
{
j = I; /* initialize new iterator to current buf position */
p = buf + I; /* get pointer for return */

check_chain(info, buf, &j, I, len);
while (j < len) /* iterate to semicolon or end */
{
if (is_chain(info, buf, &j))
break;
j++;
}

i = j + 1;
if (I >= len) 
{
i7 = len = 0; 
info->cmd_buf_type = CMD_NORM;
}

*buf_p = p;
return (_strlen(p));
}

*buf_p = buf; /* if not a chain, pass back buffer from _getline() */
return (r); /* return the length of buffer from _getline() */
}

/**
* read_buf – reads a buffer
* @info: parameter struct
* @buf: buffer
* @i: size
*
* Return: r
*/
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t r = 0;

if (*i)
return (0);
r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*i = r;
return (r);
}

/**
 * _getline - reads an entire line from stream
 * @info: pointer to struct containing buffer and buffer size
 * @ptr: pointer to buffer
 * @length: length of buffer
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t I, len;
size_t k;
ssize_t r = 0, s = 0;
char *p = 0, *new_p = 0, *c;

p = *ptr;
if (p && length)
s = *length;
if (I == len)
i = len = 0;

r = read_buf(info, buf, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);

c = _strchr(buf + I, ‘\n’);
k = c ? 1 + (unsigned int)(c – buf) : len;
new_p = _realloc(p, s, s ? s + k : k + 1);
if (!new_p) /* MALLOC FAILURE! */
return (p ? free(p), -1 : -1);

if (s)
_strncat(new_p, buf + I, k – i);
else
_strncpy(new_p, buf + I, k – I + 1);

s += k – I;
i = k;
p = new_p;

if (length)
*length = s;
*ptr = p;
return (s);
}

/**
* sigintHandler – handles SIGINT signal
* @sig_num: the signal number
*
* Return: void
*/
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts(“\n”);
_puts(“$ “);
_putchar(BUF_FLUSH);
}

