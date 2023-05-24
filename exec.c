#include "shell.h"
/**
 * executeCommand - Execute the command specified by args.
 * @args: Array of arguments.
 * @av: Array of command-line arguments.
 * @env: Array of environment variables.
 */
void executeCommand(char **args, char **av, char **env)
{
	char *str = ": No such file or directory\n";
	int fd;

	if (access(args[0], X_OK) == -1)
	{
		fd = open("/dev/stderr", O_WRONLY);
		write(fd, av[0], getLength(av[0]));
		write(fd, str, getLength(str));
		exit(EXIT_FAILURE);
	}
	if (execve(args[0], args, env) == -1)
	{
		write(STDERR_FILENO, av[0], getLength(av[0]));
		write(STDOUT_FILENO, str, getLength(str));
		exit(EXIT_FAILURE);
	}
}
