#include "shell.h"

/**
 * _getenv - an environment of a variable
 * @_n: The variable
 *
 * Return: pointer on success, NULL on failure
 */
char *_getenv(char *_n)
{
	char **_env = environ;
	size_t l = _strlen(_n);

	while (*_env != NULL)
	{
		if (_strtowcompare(_n, *_env, l) == 0 && (*_env)[l] == '=')
		{
			return (&((*_env)[l + 1]));
		}
		_env++;
	}
	return (NULL);
}

/**
 * _setenv - changing or adding an env variable
 * @_n: The variable
 * @_v: attached to the variable
 * @over_w: 1 woverwrite, 0 otherwise
 *
 * Return: 0 or -1.
 */
int _setenv(char *_n, char *_v, int over_w)
{
	char **_env = environ;
	char *new_v, *old_v;
	size_t name_l = _strlen(_n), value_l = _strlen(_v);

	new_v = malloc(name_l + value_l + 2);
	if (!new_v)
		return (-1);

	while (*_env)
	{
		if (_strtowcompare(*_env, _n, _strlen(_n)) == 0
				&& (*_env)[_strlen(_n)] == '=')
		{
			if (!over_w)
			{
				free(new_v);
				return (0);
			}
			_memcopy(new_v, _n, name_l);
			new_v[name_l] = '=';
			_memcopy(new_v + name_l + 1, _v, value_l);
			new_v[name_l + value_l + 1] = '\0';
			old_v = *_env;
			*_env = new_v;

			free(old_v);
			return (0);
		}
		_env++;
	}

	_memcopy(new_v, _n, name_l);
	new_v[name_l] = '=';
	_memcopy(new_v + name_l + 1, _v, value_l);
	new_v[name_l + value_l + 1] = '\0';
	*(_env++) = _strdup(new_v);
	*_env = NULL;
	free(new_v);

	return (0);
}

/**
 * _unsetenv - The removes an environment variable
 * @_n: The variable
 *
 * Return: 0 or -1
 */
int _unsetenv(char *_n)
{
	char **_env = environ;

	while (*_env)
	{
		if (_strtowcompare(*_env, _n, _strlen(_n)) == 0
				&& (*_env)[_strlen(_n)] == '=')
		{
			char **tmp = _env;

			while (*tmp)
			{
				*tmp = *(tmp + 1);
				tmp++;
			}
			return (0);
		}
		_env++;
	}

	return (-1);
}
