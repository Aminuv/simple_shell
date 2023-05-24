#include "shell.h"

/**
 * _no_isatty - non-interactive mode with an input
 * @p: Name.
 * @h: The history counter.
 *
 * Return: void
 */
void _no_isatty(char *p, int *h)
{
	char buffer[BUF_SIZE], **tmp, *buffer_d;
	ssize_t n;

	n = read(STDIN_FILENO, buffer, BUF_SIZE);
	buffer[n - 1] = '\0';

	buffer_d = malloc(n + 1);
	if (!buffer_d)
		exit(EXIT_FAILURE);
	buffer_d = _strcopy(buffer_d, buffer);
	buffer_d = _strip(check_comment(buffer_d));

	tmp = split(buffer_d, "\n");

	for (n = 0; tmp[n]; n++)
		handle_command(tmp[n], p, h);
	free_args(tmp);
	free(buffer_d);

}

/**
 * _isatty - interactive mode of the shell
 * @p: Name.
 * @h: The history counter.
 *
 * Return: void
 */
void _isatty(char *p, int *h)
{
	char *_cmd;

	signal(SIGINT, signal_handler);
	while (TRUE)
	{
		prompt();
		_cmd = get_command();

		handle_command(_cmd, p, h);
		free(_cmd);
	}
}

/**
 * file_input - non-interactive mode with an input
 * @avr: input from commandline
 * @p: Name.
 * @h: The history counter.
 *
 * Return: void
 */
void file_input(char **avr, char *p, int *h)
{
	char buffer[BUF_SIZE], *buffer_d = NULL, **tmp;
	ssize_t fd = 0, r = 0, n = 0;
	size_t count = 0;

	fd = open(avr[1], O_RDONLY);
	if (fd == -1)
	{
		cannot_open_error(avr[1], p, *h);
		exit(127);
	}

	while ((r = read(fd, buffer, BUF_SIZE)) > 0)
	{
		if (r == -1)
		{	free(buffer_d);
			exit(127);
		}
		buffer_d = _reallocates(buffer_d, count, count + r + 1);
		for (n = 0; n < r; n++)
			buffer_d[count++] = buffer[n];
	}
	close(fd);

	buffer_d[count] = '\0';
	buffer_d = _strip(check_comment(buffer_d));
	tmp = parse_args(buffer_d, "\n");

	for (n = 0; tmp[n]; n++)
		handle_command(tmp[n], p, h);

	free(buffer_d);
	free_args(tmp);
	close(fd);
}
