#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#define TRUE 1
#define MAX_NUM_ARGS 124
#define MAX_LINE 80
#define BUF_SIZE 1024


extern char **environ;
static __attribute__((unused)) int exit_v;


/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(char **, char *, int);
} op_t;

/*main*/
void prompt(void);
char *check_comment(char *s);
void signal_handler(__attribute__((unused)) int signal);
void free_args(char **args);

/*builtins_helpers*/
int (*get_cmd_f(char *c))(char **, char *, int);

/*builtins*/
int cd_command(char **args, char *, int);
int env_command(char **args, char *, int);
int exit_command(char **args, char *, int);
int pwd_cmd(char **args, char *, int);
int clear_cmd(char **, char *, int);


/*builtins2*/
int setenv_command(char **args, char *, int);
int unsetenv_command(char **args, char *, int);

/*cmd_handlers*/
void handle_command(char *c, char *, int *);
char **split(char *cmd, char *del);

/*cmd_helphers*/
char *get_command();
char *get_command_path(char *c);
int exec_commands(char **args, char *, int);
int exec_command(char *arg, char **args);
int echo_command(char *arg, char **args);


/*env*/
char *_getenv(char *n);
int _setenv(char *name, char *_v, int over_w);
int _unsetenv(char *n);

/*errors*/
void command_error(char *cmd, char *, int);
void synt_error(char *cmd, char *, int);
void cannot_open_error(char *cmd, char *p, int h);
void cd_error(char *cmd, char *p, int h);


/*isatty*/
void _no_isatty(char *, int *);
void _isatty(char *, int *);
void file_input(char **avr, char *, int *);


/*string helphers*/
int _strlen(char *s);
char *_strcopy(char *dst, char *ss);
int _strcompare(char *s1, char *s2);
int _strtowcompare(char *s1, char *s2, int num);
char *_strconcatenate(char *dst, char *ss);

/*string helphers*/
char **parse_args(char *_cmd, const char *del);
char *_strtok(char *str, const char *del);


/*string helphers2*/
ssize_t _getline(char **line_p, size_t *n, FILE *stream);
int _toint(char *s);
char *_strip(char *strm);
char *_memset(char *s, char b, unsigned int num);
char *_memcopy(char *dest, char *src, unsigned int num);


/*string helphers3*/
char *_strchr(char *s, char ch);
unsigned int _strsubpn(char *s, char *accp);
char *_strpbrk(char *s, char *accp);
char *_strstr(char *hay_stack, char *n_dle);
char *_strtok_r(char *str, char *_delim, char **save_p);


/*string helphers3*/
char *_strdup(char *str);
char *_tostring(int _num);
void *_reallocates(void *p, unsigned int old_s, unsigned int new_s);
char *_strncopy(char *dest, char *src, int n);


#endif

