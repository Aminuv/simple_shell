#include "shell.h"

/**
 * command_error - prints command not found
 * @cmd: command input
 * @p: Name.
 * @h: The history counter.
 *
 * Return: void
 */
void command_error(char *cmd, char *p, int h)
{
	char *hts = _tostring(h);

	write(STDOUT_FILENO, p, _strlen(p));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, hts, _strlen(hts));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, cmd, _strlen(cmd));
	write(STDOUT_FILENO, ": not found\n", 12);
	free(hts);
}

/**
 * synt_error - for prints the syntax error
 * @cmd: command input
 * @p: Name.
 * @h: the history counter.
 *
 * Return: void
 */
void synt_error(char *cmd, char *p, int h)
{
	char *hts = _tostring(h);

	write(STDOUT_FILENO, p, _strlen(p));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, hts, _strlen(hts));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "syntax error: ", 14);
	write(STDOUT_FILENO, "\"", 1);
	write(STDOUT_FILENO, cmd, 1);
	write(STDOUT_FILENO, "\" ", 2);
	write(STDOUT_FILENO, "unexpected\n", 11);
	free(hts);
}

/**
 * cannot_open_error - for prints the syntax error
 * @cmd: command input
 * @p: Name
 * @h: the history counter.
 *
 * Return: void
 */
void cannot_open_error(char *cmd, char *p, int h)
{
	char *hts = _tostring(h);

	write(STDOUT_FILENO, p, _strlen(p));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, hts, _strlen(hts));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "Can't open ", 11);
	write(STDOUT_FILENO, cmd, _strlen(cmd));
	write(STDOUT_FILENO, "\n", 1);
	free(hts);
}

/**
 * cd_error - prints syntax error
 * @cmd: cmd input
 * @p: Name
 * @h: history counter.
 *
 * Return: void
 */
void cd_error(char *cmd, char *p, int h)
{
	char *hts = _tostring(h);

	write(STDOUT_FILENO, p, _strlen(p));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, hts, _strlen(hts));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	write(STDOUT_FILENO, cmd, _strlen(cmd));
	write(STDOUT_FILENO, "\n", 1);
	free(hts);
}
