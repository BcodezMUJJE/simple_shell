#include "shell.h"

/**
* get_environ –function returns the string array copy of our environ
* @info: a structure that contains  potential arguments used to maintain
* constant function prototype.
* Return: Always 0
*/
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}

return (info->environ);
}

/**
 * _unsetenv - function that unsets an environment variable
 * @info: pointer to info_t struct
 * @var: pointer to char variable
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(info_t *info, char *var)
{
    list_t *node = info->env;
    size_t i = 0;

    if (!node || !var)
        return 0;

    while (node)
    {
        char *p = node->str;
        while (*p && *p != '=')
            p++;
        
        if (*p == '=' && _strcmp(node->str, var) == 0)
        {
            info->env_changed = delete_node_at_index(&(info->env), i);
            i = 0;
            node = info->env;
            continue;
        }

        node = node->next;
        i++;
    }

    return info->env_changed;
}

/**
 * _setenv - function that sets an environment variable
 * @info: pointer to info_t struct
 * @var: pointer to char variable
 * @value: pointer to char variable
 *
 * Return: 0 always
 */
int _setenv(info_t *info, char *var, char *value)
{
    char *buf = NULL;
    list_t *node;
    char *p;
    
    if (!var || !value)
        return 0;

    buf = malloc(_strlen(var) + _strlen(value) + 2);
    if (!buf)
        return 1;

    _strcpy(buf, var);
    _strcat(buf, "=");
    _strcat(buf, value);

    node = info->env;
    while (node)
    {
        p = node->str;
        while (*p && *p != '=')
            p++;
        
        if (*p == '=' && _strcmp(node->str, var) == 0)
        {
            free(node->str);
            node->str = buf;
            info->env_changed = 1;
            return 0;
        }

        node = node->next;
    }

    add_node_end(&(info->env), buf, 0);
    free(buf);
    info->env_changed = 1;
    return 0;
}
