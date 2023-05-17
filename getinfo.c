#include "shell.h"

/**
* clear_info – clear info_t struct
* @info: struct address
*/
void clear_info(info_t *info)
{
info->arg = 0;
info->argv = 0;
info->path = 0;
info->argc = 0;
}

/**
* set_info – sets info_t struct
* @info: struct address
* @av: argument vector
*/
void set_info(info_t *info, char **av)
{
Int I = 0;

info->fname = av[0];
if (info->arg)
{
info->argv = strtow(info->arg, “ \t”);
if (!info->argv)
{
info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strdup(info->arg);
info->argv[1] = 0;
}
}
for (I = 0; info->argv && info->argv[i]; i++)
;
info->argc = I;

replace_vars(info);
replace_alias(info);
}
}

/**
* free_info – frees info_t struct areas
* @info: address of struct
* @all: true if freeing all fields
*/
void free_info(info_t *info, int all)
{
ffree(info->argv);
info->argv = 0;
info->path = 0;
if (all)
{
if (!info->cmd_buf)
free(info->arg);
if (info->env)
free_list(&(info->env));
if (info->history)
free_list(&(info->history));
if (info->alias)
free_list(&(info->alias));
ffree(info->environ);
info->environ = 0;
bfree((void **)info->cmd_buf);
if (info->readfd > 2)
close(info->readfd);
_putchar(BUF_FLUSH);
}
}
