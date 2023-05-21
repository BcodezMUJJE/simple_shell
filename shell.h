#ifndef SHELL_H
#define SHELL_H
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include "_getline.h"

<<<<<<< HEAD
/* for read/write buffers */
#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

/* for command chaining */
#define CMD_CHAIN	3
#define CMD_OR			1
#define CMD_AND			2
#define CMD_NORM	0
/* for convert_number() */
#define USE_STRTOK 0
=======
/* read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* command chaining */
#define CMD_NORM        0
#define CMD_OR          1
#define CMD_AND         2
#define CMD_CHAIN       3
#define CMD_PIPE        4

/* to convert_number() */
#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED        2

/* 1 if using system getline() */
>>>>>>> ef67d6b3c8854f7ab76a5afb069667805d5bcda2
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE       ".hsh_history"
#define HIST_MAX        4096

<<<<<<< HEAD
extern char **environ;
/**
 * struct  liststr - A singly linked list
 * @str: A string
 * @num: A number field
 * @next: A point to the next node
 */
=======
#define HEREDOC_FD -2 /*will set if using HEREDOC */

/* Starts for use  of dynamically reallocating arrays */ 
#define STARTING_ARR_SIZE 10

/* location of the file to execute its contents at startup */
#define STARTUP_FILE ".hshrc"

extern char **environ;

 /** 
  * struct liststr - singly linked list 
  * @num: the number field 
  * @str: a string 
  * @next: points to the next node 
  */
>>>>>>> ef67d6b3c8854f7ab76a5afb069667805d5bcda2
typedef struct liststr
{
int num;
char *str;
struct liststr *next;
} list_t; 

/**
<<<<<<< HEAD
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
=======
 *struct passinfo - contains pseudo-arguements to pass into a function, 
 * which allows uniform prototype for function pointer struct
 * @arg: string generated from getline containing arguements
 * @argv: an array of strings generated from arg 
 * @path: a string path for the current command 
 * @argc: the argument count 
 * @line_count: the count of errors
 * @err_num: the error code for exit()s 
 * @linecount_flag: if on count this line of input 
 * @fname: the program filename 
 * @env: linked list local copy of environ 
 * @environ: custom modified copy of environ from LL env 
 * @history: the history node 
 * @alias: the alias node 
 * @env_changed: on if environ was changed 
 * @status: the return status of the last exec'd command 
 * @cmd_buf: address of pointer to cmd_buf, on if chaining 
 * @cmd_buf_type: CMD_type ||, &&, ; 
 * @readfd: the fd from which to read line input 
 * @histcount: the history line number count 
 * @left_redirect_from_fd: the fd to left redirect from 
 * @left_append: true if heredoc 
 * @right_redirect_from_fd: fd right redirecting from (default 1) 
 * @right_redirect_to_fd: fd right redirecting to 
 * @right_append: true if right stream appends 
 * @heredoc: value of HEREDOC delimeter 
 * @heredoc_txt: accumulated HEREDOC lines 
 * @heredoc_cmd: the command to pipe HEREDOC line 
 * @help: help flags 
 * @pipefd: fd pipe for interprocess communication | pipe 
 * @startup_fd: fd of startup file or -1
 * @dup_stdout: saved duplicate of stdout for restoration after redirect 
 * @dup_stdin:saved duplicate of stdin for restoration after redirect 
 */ 
>>>>>>> ef67d6b3c8854f7ab76a5afb069667805d5bcda2
typedef struct passinfo
{
char *fname;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
int status;
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;
int err_num;
int linecount_flag;

char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */ 
int cmd_buf_type; /* CMD_type ||, &&, ; */ 
int readfd;
int histcount;
<<<<<<< HEAD
char *fname;
}
info_t;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
/**
 * struct builtin - it contains a builtin string and a related function
 * @func: function
 * @type: a builtin command flag
 */
=======

int left_redirect_from_fd;
int left_append;

char *heredoc;
char *heredoc_txt;
char *heredoc_cmd;
char *help;
int right_redirect_from_fd;
int right_redirect_to_fd;
int right_append;

int pipefd[2];
int startup_fd; 
int dup_stdin;
int dup_stdout;
  
} info_t; 
  
 #define INFO_INIT \ 
 {NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \ 
         0, 0, 0, -1, 0, 1, -1, 0, NULL, NULL, NULL, NULL, {0}, -1, 0, 0} 
  
 /** 
 *struct builtin - containing  builtin string and related function
 *@type: command flag of builtin
 *@func: the function
 */ 
>>>>>>> ef67d6b3c8854f7ab76a5afb069667805d5bcda2
typedef struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_table; 


/* hsh.c */ 
int hsh(info_t *, char **); 
int find_builtin(info_t *); 
void find_cmd(info_t *); 
void fork_cmd(info_t *); 
void handle_redirects(info_t *info); 

/* path.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* help.c */
void help(void);
void help_cd(info_t *);
void help_exit(info_t *);
void help_help(info_t *);
void help_history(info_t *);

<<<<<<< HEAD
/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
=======
/* help_2.c */
void help_alias(info_t *);
void help_echo(info_t *);
void help_pwd(info_t *);
>>>>>>> ef67d6b3c8854f7ab76a5afb069667805d5bcda2

/* errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

<<<<<<< HEAD
/* toem_string1.c */
char *_strcpy(char *, char *);
void _puts(char *);
=======
/* strings.c */ 
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* strings2.c */
char *_strcpy(char *, char *);
>>>>>>> ef67d6b3c8854f7ab76a5afb069667805d5bcda2
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

<<<<<<< HEAD
/* toem_exits.c */
=======
/* strings3.c */
>>>>>>> ef67d6b3c8854f7ab76a5afb069667805d5bcda2
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char *_strchrlast(char *s, char c);

/* string4.c */ 
char **strtow(char *, char *);
char **strtow2(char *, char);

/* memory_functions */
char *_memcpy(char *dest, char *src, unsigned int n);
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int bfree(void **);

<<<<<<< HEAD
/* toem_atoi.c */
=======
/* more_functions.c */
>>>>>>> ef67d6b3c8854f7ab76a5afb069667805d5bcda2
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* more_functions2.c */ 
int _erratoi(char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* builtin1.c */
int _myexit(info_t *);
int _mycd(info_t *);
<<<<<<< HEAD
int _myhelp(info_t *);

/* toem_builtin1.c */
=======
int _myhelp(info_t *); 
char *help_flag_check(info_t *, char**);

/* builtin2.c */
>>>>>>> ef67d6b3c8854f7ab76a5afb069667805d5bcda2
int _myhistory(info_t *);
int _myalias(info_t *);

/* getline.c module */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* info.c module */
void clear_info(info_t *); 
int set_info(info_t *info, char **av);
void free_info(info_t *, int);
void print_info(info_t *info);

/* env.c module */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* env2.c module */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
void print_prompt(info_t *);

/* file_io_functions.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount); 
int renumber_history(info_t *info);
  
/* liststr.c module */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* liststr2.c module */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* chain.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

/* redirect.c */
void parse_left_redirect(info_t *info);
void parse_right_redirect(info_t *info);
int open_redirect(info_t *info, char *file, int left);
size_t parse_heredoc(info_t *info, char **buf, size_t r);
void restore_stdfd(info_t *info);
 
/* pipe.c */ 
void open_pipe(info_t *info);

/* error.c */ 
void print_error(info_t *, char *);
void print_error_noarg(info_t *info, char *estr);

/* startup.c */
int open_file(info_t *info, char *name, int silent);
void read_startup_file(info_t *info);

/* time.c */
char *create_date(void);
char *create_time(int);
char *its_weekday(int);
char *its_month(int);

#endif
