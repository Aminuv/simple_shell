#include "shell.h"

/**
 * _strchr - for locates the character for a string.
 * @s: string input.
 * @ch: character to locate.
 *
 * Return: pointer.
 */
char *_strchr(char *s, char ch)
{
	int i = 0;

	do {
		if (*(s + i) == ch)
			return (s + i);
		i++;
	} while (s[i - 1] != '\0');

	return ('\0');
}

/**
 * _strsubpn - the length of a prefix substring
 * @s: string for the first input
 * @accp: string for the second input
 *
 * Return: numbers
 */
unsigned int _strsubpn(char *s, char *accp)
{
	int i = 0;
	int cnt = 0;

	while (s[i] != '\0')
	{
		int j = 0;

		while (accp[j] != '\0')
		{
			if (s[i] == accp[j])
			{
				cnt++;
				break;
			}
			j++;
		}
		if (accp[j] == '\0')
			break;
		i++;
	}
	return (cnt);
}

/**
 * _strpbrk - the searches of a string for any of a set of bytes.
 * @s: tring for the first input
 * @accp: string for the second input
 *
 * Return: pointer
 */
char *_strpbrk(char *s, char *accp)
{
	int i = 0;

	while (s[i] != '\0')
	{
		int j = 0;

		while (accp[j] != '\0')
		{
			if (s[i] == accp[j])
				return (s + i);
			j++;
		}
		i++;
	}
	return (s = 0);
}

/**
 * _strstr - located the substring.
 * @hay_stack: string.
 * @n_dle: substring.
 *
 * Return: pointer.
 */
char *_strstr(char *hay_stack, char *needle)
{
	int i;

	if (*n_dle == 0)
		return (hay_stack);

	while (*hay_stack)
	{
		i = 0;

		if (needle[i] == hay_stack[i])
		{
			do {
				if (needle[i + 1] == '\0')
					return (hay_stack);
				i++;
			} while (needle[i] == hay_stack[i]);
		}
		hay_stack++;
	}
	return (NULL);
}

/**
 * _strtok_r - breaks a string.
 * @str: input string.
 * @_delim: specifies a set of bytes.
 * @save_p: pointer to a char.
 *
 * Return: pointer.
 */
char *_strtok_r(char *str, char *_delim, char **save_p)
{
	char *token;

	if (str == NULL)
		str = *save_p;

	str += _strsubpn(str, _delim);
	if (*str == '\0')
		return (NULL);

	token = str;
	str = _strpbrk(token, _delim);
	if (str == NULL)
	{
		*save_p = _strchr(token, '\0');
	}
	else
	{
		*str = '\0';
		*save_p = str + 1;
	}

	return (token);
}
