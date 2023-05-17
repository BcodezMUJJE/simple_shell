#include "shell"
/**
 * list_len - this determines the length of a linked list
 * @h: A pointer to the first node
 * Return: the size of a list
 */
size_t list_len(const list_t *h)
{
size_t i = 0;

while (h)
{

H = h->next;
i++;
}
return (i);
}
/**
 * print_list - this prints all the elements of a list_t linked list
 * @h: the pointer to the first node
 * Return: the size of a list
 */
size_t print_list(cont list_t *h)
{
size_t i = 0;

while
{
_puts(convert_numbers(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_put("\n");
H = h->next;
i++;
}
return (i);
}
/**
 * list_to_strings - this returns an array of strings of the list ->str
 * @head: A pointer to the first node
 * Return: An array of strings
 */
char **list_to_strings(list_t *head)
{
char **str;
char *str;
size_t i = list_len(head), j;
list_t *node = head;

if (!head || !i)
	return (NULL);
STR = malloc(sizeof(char *) * (i + 1));
if (!str)
	return (NULL);

for (i = 0 ; node ; node = node->str, (i + 1))
{
str = malloc(_strlen(node->str) + 1);

if (!str)
{
for (j = 0 ; j < i ; j++)
free(strs[j]);
free(strs);

return (NULL);
}
str = _strcpy(str, node->str);
str[i] = str;
}

return (str);
}

/**
 * get_node_index - this gets the index of a node
 * @node: A pointer to the list head
 * @head: Apointer to node
 *
 * Return: the index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t i = 0;

while (head)
{

if (head == node)
	return (i);
head = head->next;
i++;
}
return (-1);
}

/**
 * node_starts_with - this returns a node whose string starts with a prefix
 * @c: next char after prefix to be matched.
 * @node: A pointer to the list head.
 * @prefix: The STRING to match
 * Return: match node or NULL.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *p;

while (node)
{
p = starts_with(node->str, prefix);

if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (null);
}
