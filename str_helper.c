#include "shell.h"

/**
 * _strlen - a returns fo length to the string
 * @s: string length.
 * 
 * Return: void.
 */
int _strlen(char *s)
{
	int count = 0;

	while ((*(s++) != '\0'))
		count++;

	return (count);
}

/**
 * _strcopy - copies the string.
 * @dst: string
 * @ss: source string
 *
 * Return: dst
 */
char *_strcopy(char *dst, char *ss)
{
	int i = 0;

	if (dst == NULL)
		return (NULL);

	while (ss[i] != '\0')
	{
		dst[i] = ss[i];
		i++;
	}

	dst[i] = '\0';

	return (dst);
}

/**
 * _strcompare - compares two strings
 * @s1: frst string
 * @s2: second string
 *
 * Return: +ve or -ve value otherwise
 */
int _strcompare(char *s1, char *s2)
{
	int i = 0;
	int sum;

	while (!(s1[i] == '\0' || s2[i] == '\0'))
	{
		sum = s1[i] - s2[i];

		if (sum != 0)
			break;
		i++;
	}
	return (sum);
}

/**
 * _strtowcompare - compares two strings
 * @s1: frst string
 * @s2: second string
 * @num: max number of bytes to check
 *
 * Return: 0 if s1 and s2 are the same, +ve or -ve value otherwise
 */
int _strtowcompare(char *s1, char *s2, int num)
{
	int i = 0;
	int sum;

	while (i < num)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return (-1);

		sum = s1[i] - s2[i];

		if (sum != 0)
			break;
		i++;
	}
	return (sum);
}

/**
 * _strconcatenate - concatenates two strings
 * @dst: destination string
 * @ss: source string
 *
 * Return: dst
 */
char *_strconcatenate(char *dst, char *ss)
{
	int i = 0;

	while (1)
	{
		if (dst[i] == '\0')
		{
			int j = 0;

			while (1)
			{
				dst[i++] = ss[j++];

				if (ss[j - 1] == '\0')
					break;
			}

			break;
		}
		i++;
	}
	return (dst);
}
