#include "shell.h"

/**
 * get_cmd_f - Tehe function that point for builtins commands.
 * @c: input.
 *
 * Return: call a function
 */
int (*get_cmd_f(char *c))(char **, char*, int)
{
	op_t builtins[] = {
		{"cd", cd_cmd},
		/*{"exit", exit_cmd},*/
		{"env", env_cmd},
		{"/usr/bin/env", env_cmd},
		{"/bin/env", env_cmd},
		{"setenv", setenv_cmd},
		{"unsetenv", unsetenv_cmd},
		{NULL, NULL}
	};
	int i = 0;

	while (builtins[i].op)
	{
		if (_strcompare(builtins[i].op, c) == 0)
			return (builtins[i].f);
		i++;
	}
	return (NULL);
}
