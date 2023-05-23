#include "shell.h"

/**
 * setenv_command - The setenv command for implement
 * @args: Passed arguments in input.
 * @p: Name.
 * @h: The history counter.
 *
 * Return:  -1 on failure,0 on success
 */
int setenv_command(char **args, char *p, int h)
{
	if (args[1] && args[2])
		_setenv(args[1], args[2], 0);

	(void)p;
	(void)h;
	return (0);
}




/**
 * unsetenv_command - The unsetenv command for implement
 * @args: Passed arguments in input.
 * @p: Name.
 * @h: The history counter.
 *
 * Return:  -1 on failure,0 on success
 */
int unsetenv_command(char **args, char *p, int h)
{
	if (args[1])
		_unsetenv(args[1]);

	(void)p;
	(void)h;
	return (0);
}
