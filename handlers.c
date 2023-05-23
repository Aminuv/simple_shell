#include "shell.h"

/**
 * check_comment - The checks if the input contains
 * @s: a string input
 *
 * Return: input
 */
char *check_comment(char *s)
{
	int i = 0;
	char *st = malloc(_strlen(s) + 1);

	if (st == NULL)
		return (NULL);

	while (s[i])
	{
		if (s[i] == '#')
		{
			st[i] = '\0';
			free(s);
			return (st);
		}
		st[i] = s[i];
		i++;
	}
	free(st);
	return (s);
}

/**
 * handle_command - input from commandline
 * @c: input
 * @p:  Name.
 * @h: The history counter.
 *
 * Return: 0
 */
void handle_command(char *c, char *p, int *h)
{
	int i = 0;
	char **tok = split(c, ";");

	*h += 1;
	while (tok[i])
	{
		char **subtok = split(tok[i], " ");

		if ((i == 0) && (_strtowcompare(subtok[i], "exit", 4) == 0))
		{
			int status = 0;
			if (subtok[1])
				status = _toint(subtok[1]);
			else
				status = errno;

			free(c);
			free_args(subtok);
			free_args(tok);
			exit(status);
		}
		exec_commands(subtok, p, *h);
		free_args(subtok);
		i++;
	}
	free_args(tok);
}

/**
 * split - input into array of strings
 * @c: an input
 * @del: Refrence delimeter
 *
 * Return: array on success, NULL on failure
 */
char **split(char *c, char *del)
{
	char **args, *tmp = c;
	int i = 0, j = 0, height = 0, width = 0;
	int row = 0, start = 0, ref, n = _strlen(del);

	for (; c[j]; j++)
	{
		if (_strtowcompare(c + j, del, n) == 0 || c[j + 1] == '\0')
			height++;
	}
	args = malloc(sizeof(*args) * (height + 1));
	if (!args)
		return (NULL);

	while (*c)
	{
		i++;
		if (_strtowcompare(c, del, n) == 0 || *(c + 1) == '\0')
		{
			if (*(c + 1) != '\0')
				ref = i - 1;
			else
				ref = i;
			width = ref - start;
			args[row] = malloc(sizeof(char) * width + 1);
			if (args[row] == NULL)
			{
				free_args(args);
				return (NULL);
			}
			_strncopy(args[row], tmp + start, width);
			args[row][width] = '\0';
			args[row] = _strip(args[row]);

			start = ref + n;
			row++;
		}
		c++;
	}
	args[row] = NULL;
	return (args);
}
