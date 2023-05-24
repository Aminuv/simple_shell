#include "shell.h"

/**
 * cd_command - The cd command implementing.
 * @args: Passed an arguments fot the input .
 * @p: Name.
 * @h: The history counter.
 *
 * Return: 0 on success, -1 on failure
 */
int cd_command(char **args, char *p, int h)
{
	if (args[1] == NULL)
		chdir(_getenv("HOME"));


	else if (chdir(args[1]) == -1)
		cd_error(args[1], p, h);

	return (0);
}

/**
 * env_command - The env command for implements.
 * @args: Passed an arguments for input.
 * @p: Name.
 * @h: History.
 *
 * Return: -1 on failure, 0 on success.
 */
int env_command(char **args, char *p, int h)
{
	int i = 0;

	if (environ)
	{
		while (environ[i])
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}

	(void)p;
	(void)h;
	(void)args;
	return (0);
}

/**
 * exit_command - implements exit command
 * @args: arguments passed in.
 * @p: program name.
 * @h: history counter.
 *
 * Return: 0 on success, -1 on failure
 */
int exit_command(char **args, char *p, int h)
{
	if (h && p)
	{}
	if (args[1] == NULL)
	{
		free_args(args);
		exit(0);
	}
	else
	{
		int status = _toint(args[1]);

		free_args(args);
		exit(status);
	}
	return (0);
}
