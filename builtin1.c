#include "shell.h"

/**
* _myhistory – shows the history list, one command by line, continues
* with line numbers, starting at 0.
* @info: structure that contains potential arguments. Used to maintain
*        constant function prototype.
*  Return: Always 0
*/
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
* unset_alias – sets alias to string
* @info: struct of parameter
* @str: its string alias
*
* Return: Always 0 on success and 1 on error
*/
int unset_alias(info_t *info, char *str)
{
char *p, c;
int ret;

p = _strchr(str, ‘=’);
if (!p)
return (1);
c = *p;
*p = 0;
Ret = delete_node_at_index(&(info->alias),
Get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = c;
Return (ret);
}

/**
* set_alias – sets alias to string
* @info: parameter struct
* @str: the string alias
*
* Return: Always 0 on success, 1 on error
*/
int set_alias(info_t *info, char *str)
{
char *p;

p = _strchr(str, ‘=’);
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == 0);
}

/**
* print_alias – it print an alias string
* @node:  alias node
*
* Return: 0 on success and 1 on error
*/
int print_alias(list_t *node)
{
char *p = 0, *a = 0;

if (node)
{
P = _strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\"');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
* _myalias – imitate the alias builtin
* @info: structure that contains potential arguments, used in maintaining
* constant function prototype.
*  Return: Always 0
*/
int _myalias(info_t *info)
{
int I = 0;
char *p = 0;
list_t *node = 0;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (I = 1; info->argv[i]; i++)
{
p = _strchr(info->argv[i], ‘=’);
if (p)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], ‘=’));
}

return (0);
}