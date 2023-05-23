#include "shell.h"

/**
 * _getline - The getline that reads an input from stream.
 * @line_p: a buffer to store read input
 * @n: size of the buffer
 * @strm: input stream
 *
 * Return: number of bytes read
 */

ssize_t _getline(char **line_p, size_t *n, __attribute__((unused)) FILE * strm)
{
	ssize_t read_b = 0;
	size_t cnt = 0;
	char c;

	if (*line_p == NULL || *n == 0)
	{
		*line_p = malloc(BUF_SIZE);
		if (*line_p == NULL)
			return (-1);

		*n = MAX_LINE;
	}
	read_b = read(STDIN_FILENO, &c, 1);

	while (read_b)
	{
		if (read_b == -1)
		{
			free(*line_p);
			return (-1);
		}

		if (c == '\n')
			break;

		if (cnt >= BUF_SIZE)
			*line_p = _reallocates(*line_p, cnt, cnt + 1);
		(*line_p)[cnt++] = c;
		read_b = read(STDIN_FILENO, &c, 1);
	}
	if (read_b == 0 && cnt == 0)
		return (-1);

	(*line_p)[cnt] = '\0';
	return (read_b);
}

/**
 * _toint - The convert a string to an integer.
 * @s: string.
 *
 * Return: int value
 */
int _toint(char *s)
{
	int cnve = 0;
	int i = 0;
	unsigned int R = 0;

	while ((s[i] != '\0'))
	{
		if (s[i] >= '0' && s[i] <= '9')
			break;
		else if (s[i] == '-')
			cnve++;

		i++;
	}

	while ((s[i] != '\0'))
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			break;

		R = R * 10 + s[i] - '0';
		i++;
	}

	if ((cnve % 2) != 0)
		R = -R;

	return (R);
}

/**
 * _strip - The function that removes white spaces from left and right
 * @strm: input.
 *
 * Return: string.
 */

char *_strip(char *strm)
{
	int i = 0, j = 0;
	char *s_str;

	s_str = malloc(_strlen(strm) + 1);
	if (!s_str)
		return (NULL);

	while (strm[i] == ' ')
		i++;

	while (strm[i])
	{
		if (strm[i] == ' ' && (strm[i + 1] == ' ' || strm[i + 1] == '\0'))
		{
			i++;
			continue;
		}
		s_str[j++] = strm[i++];
	}

	s_str[j] = '\0';

	free(strm);
	return (s_str);
}

/**
 * _memset - for fills the memory with a constant byte
 * @s: memory area
 * @b: constant byte
 * @num: number of bytes
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		*(s + i) = b;
	return (s);
}

/**
 * _memcpy - for copies the memory from an area.
 * @dest:area destination
 * @src: area source
 * @num: number of bytes
 *
 * Return: pointer to dest
 */
char *_memcopy(char *dest, char *src, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		*(dest + i) = src[i];
	return (dest);
}
