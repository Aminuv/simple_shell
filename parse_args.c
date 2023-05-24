#include "shell.h"

/**
 * parse_args - split the input into an array of the strings
 * @_cmd: input.
 * @del: the refrence delimeter
 *
 * Return: array of string on success, NULL on failure
 */
char **parse_args(char *_cmd, const char *del)
{
	char **args, *t, *tmp_;
	int i = 0;

	if (!_cmd || !del)
		return (NULL);

	tmp_ = _strdup(_cmd);

	t = _strtok(tmp_, del);
	for (; t; t = _strtok(NULL, del))
		i++;
	free(tmp_);

	args = malloc(sizeof(char *) * (i + 1));
	if (!args)
		return (NULL);

	t = _strtok(_cmd, del);
	for (i = 0; t; t = _strtok(NULL, del))
		args[i++] = _strdup(t);

	args[i] = NULL;

	return (args);
}

/**
 * _strtok - for breaking the string into a sequence of
 *           zero or more nonempty tokens.
 * @str: input.
 * @del: specifies a set of bytes.
 *
 * Return: pointer, or NULL.
 */
char *_strtok(char *str, const char *del)
{
	static char *saveptr;
	char *t;

	if (str)
		saveptr = str;
	if (!saveptr)
		return (NULL);

	t = saveptr;
	while (*saveptr)
	{
		const char *p_d = del;

		while (*p_d)
		{
			if (*saveptr == *p_d)
			{
				*saveptr = '\0';
				saveptr++;

				if (t != saveptr)
				{
					return (t);
				}
				else
				{
					t++;
					break;
				}
			}
			p_d++;
		}
		saveptr++;
	}
	saveptr = NULL;
	if (t == saveptr)
		return (NULL);
	else
		return (t);
}
