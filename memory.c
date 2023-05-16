#include "shell.h"
/**
 * bfree - this frees a pointer & NULLs the address
 * @ptr: the sddress  of the pointer to free
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
