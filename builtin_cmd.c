#include "shell.h"

/**
 * get_command_f - Tehe function that point for builtins commands.
 * @c: input.
 *
 * Return: call a function
 */
int (*get_command_f(char *c))(char **, char*, int)
{
	op_t builtins[] = {
		{"cd", cd_command},
		{"env", env_command},
		{"/usr/bin/env", env_command},
		{"/bin/env", env_command},
		{"setenv", setenv_command},
		{"unsetenv", unsetenv_command},
		{NULL, NULL}
	};
	int i = 0;

	while (builtins[i].op)
	{
		if (_strcmp(builtins[i].op, c) == 0)
			return (builtins[i].f);
		i++;
	}
	return (NULL);
}
