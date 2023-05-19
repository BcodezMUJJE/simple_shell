#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>

/* for read/write buffers*/
#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
/* for command chaining */
#define CMD_CHAIN       3
#define CMD_OR                  1
#define CMD_AND                 2
#define CMD_NORM        0
/* for convert_number() */
#define USE_STRTOK 0
#define USE_GETLINE 0

#define HIST_MAX        4096
#define HIST_FILE       ".simple_shell_history"

extern char **environ;
/**
 * struct  liststr - A singly linked list
 * @str: A string
 * @num: A number field
 * @next: A point to the next node
 */
typedef struct liststr
{
    int num;
    char *str;
    struct liststr *next;
} list_t;
/**
 * struct passinfo - it comtains psuedo-arguments that are to be
 * passed into a functionallowing a uniform prototype for  the
 * function pointer struct
 * @arg: A string formed from a getline containing arguments
 * @argv: An array of strings that is generated from arg
 * @path: A string path of the current command
 * @histcount: History line number count
 * @readfd: The fd from which to read line input
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @cmd_buf: The address pointer to cmd_buf, on if chaining
 * @status: return status of the last exec'd command
 * @argc: An argument count
 * @line_count: An error count
 * @err_num: An error count code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: program filename
 * @env: The linked list local copy environ
 * @environ: The custom modified copy of environ from LL env
 * @alias: The alias node
 * @history: History node
 * @env_changed: On if environ was changed
 */
typedef struct passinfo {
    int status;
    int env_changed;
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int histcount;
    int readfd;
    int cmd_buf_type;
    char **cmd_buf;
    unsigned int line_count;
    unsigned int err_num;
    unsigned int linecount_flag;
    char fname[1024];
    list_t **env;
    list_t **environ;
} passinfo_t;

#endif /* _SHELL_H_*/
