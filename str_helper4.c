#include "shell.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 * @str: input string.
 *
 * Return: array pointer.
 */
char *_strdup(char *str)
{
	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		int i = 0, j = 0;
		char *p = NULL;

		i = _strlen(str);

		p = malloc(sizeof(char) * i + 1);
		if (p == NULL)
			return (NULL);

		for (j = 0; j < i; j++)
			*(p + j) = *(str + j);

		p[i] = '\0';

		return (p);
	}
}

/**
 * _tostring - the convert of a positive integer.
 * @_num: integr.
 *
 * Return: int
 */
char *_tostring(int _num)
{
	int ch_neg = _num;
	char *out_p, tmp;
	unsigned int i, l = 0;

	out_p = malloc(1);
	if (out_p == NULL)
		return (NULL);
	if (_num < 0)
		_num = -_num;
	else if (_num == 0)
	{
		out_p[l++] = '0';
		out_p = _reallocates(out_p, l, l + 1);
		out_p[l] = '\0';
		return (out_p);
	}
	while (_num)
	{
		out_p[l++] = _num % 10 + '0';
		_num = _num / 10;
		out_p = _reallocates(out_p, l, l + 1);
		if (out_p == NULL)
			return (NULL);
	}
	if (ch_neg < 0)
	{
		out_p[l++] = '-';
		out_p = _reallocates(out_p, l, l + 1);
		if (out_p == NULL)
			return (NULL);
	}
	out_p[l] = '\0';
	for (i = 0; i < l / 2; i++)
	{
		tmp = out_p[i];
		out_p[i] = out_p[l - i - 1];
		out_p[l - i - 1] = tmp;
	}

	return (out_p);
}

/**
 * _reallocates - reallocates the memory.
 * @p: pointer to the memory previously allocated
 * @old_s: the size.
 * @new_s: the new size.
 *
 * Return: pointer.
 */
void *_reallocates(void *p, unsigned int old_s, unsigned int new_s)
{
	void *_p;
	unsigned int i = 0;

	if (new_s == old_s)
	{
		return (p);
	}
	else if (new_s == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}
	else if (p == NULL)
	{
		_p = malloc(new_s);
		if (_p == NULL)
			return (NULL);
		else
			return (_p);
	}
	else
	{
		char *cast_p, *cast_ptr;

		_p = malloc(new_s);
		if (_p == NULL)
			return (NULL);
		cast_p = (char *)_p;
		cast_ptr = (char *)p;
		for (; i < old_s; i++)
			cast_p[i] = cast_ptr[i];

		cast_p = (void *)cast_p;

		free(cast_ptr);
		return (cast_p);
	}
}

/**
 * _strncopy - for the copies of a strings.
 * @dest: destination string.
 * @src: source string.
 * @n: bytes.
 *
 * Return: dest
 */
char *_strncopy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		if (dest[i] == '\0')
			break;
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
