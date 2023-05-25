#include "shell.h"

/**
 * get_command - get the commands from the shell.
 * Return: command input from the shell
 */
char *get_command()
{
	char *c = NULL;
	size_t Size = 0;
	int read = 0;

	read = _getline(&c, &Size, stdin);
	if (read == -1)
	{
		free(c);
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	if (read > 0 && c[read - 1] == '\n')
		c[read - 1] = '\0';
	return (_strip(check_comment(c)));
}

/**
 * get_command_path - get The command p_ for input commands without p_.
 * @c: command
 * Return: input
 */
char *get_command_path(char *c)
{
	int i = 0;
	char *p_env, *p_, *p_copy, **d;

	p_env = _getenv("PATH");
	if (!p_env)
		return (NULL);

	p_ = malloc(PATH_MAX);
	if (!p_)
		return (NULL);

	p_copy = _strdup(p_env);
	if (!p_copy)
	{
		free(p_);
		return (NULL);
	}

	d = split(p_copy, ":");
	while (d[i])
	{
		_memset(p_, 0, PATH_MAX);
		_strconcatenate(p_, d[i]);
		_strconcatenate(p_, "/");
		_strconcatenate(p_, c);

		if (access(p_, X_OK) == 0)
		{
			free_args(d);
			free(p_copy);
			return (p_);
		}
		i++;
	}
	free(p_);
	free(p_copy);
	free_args(d);
	return (NULL);
}

/**
 * exec_commands - The executes commands from shell.
 * @args: commands for input.
 * @p: Name.
 * @h: the history counter.
 *
 * Return: input.
 */
int exec_commands(char **args, char *p, int h)
{
	char *path;

	if (get_command_f(args[0]))
	{
		get_command_f(args[0])(args, p, h);
		return (exit_v = 0);
	}

	if (*args[0] != '/')
	{
		path = get_command_path(args[0]);
		if (!path)
		{
			command_error(args[0], p, h);
			return (exit_v = 127);
		}
	}
	else
	{
		path = args[0];
		if (access(path, X_OK) != 0)
		{
			command_error(args[0], p, h);
			return (exit_v = 127);
		}
	}

	if (echo_command(path, args) == 0)
	{
		if (*args[0] != '/')
			free(path);
		return (0);
	}
	exec_command(path, args);

	if (*args[0] != '/')
		free(path);

	return (0);
}

/**
 * exec_command - The executes commands from the shell.
 * @arg: executable
 * @args: input.
 *
 * Return: input.
 */
int exec_command(char *arg, char **args)
{
	int s;
	pid_t _pid;

	_pid = fork();
	if (_pid == 0)
	{
		if (execve(arg, args, environ) == -1)
		{
			perror(arg);
			free(arg);
			exit(EXIT_FAILURE);
		}
	}
	else if (_pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(_pid, &s, 0);
	return (WEXITSTATUS(s));
}

/**
 * echo_command - checks for $ in the echo command
 * @arg: executable
 * @args: input.
 *
 * Return: 0 or -1.
 */
int echo_command(char *arg, char **args)
{
	if (_strcmp(arg, "/usr/bin/echo") == 0 && *(args[1]) == '$')
	{

		if (_strcmp(args[1], "$$") == 0)
		{
			char *_pid = _tostring(getpid());

			write(STDOUT_FILENO, _pid, _strlen(_pid));
			write(STDOUT_FILENO, "\n", 1);
			free(_pid);
		}
		else if (_strcmp(args[1], "$?") == 0)
		{
			char *_exit_v = _tostring(exit_v);

			write(STDOUT_FILENO, _exit_v, _strlen(_exit_v));
			write(STDOUT_FILENO, "\n", 1);
			free(_exit_v);
		}
		else
		{
			char *tmp = _strdup(args[1] + 1);
			char *env = _getenv(tmp);

			write(STDOUT_FILENO, env, _strlen(env));
			write(STDOUT_FILENO, "\n", 1);
			free(tmp);
		}
		return (0);
	}
	return (-1);
}
