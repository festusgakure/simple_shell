#include "shell.h"

/**
 * executeCommand - Execute the command specified by args.
 * @args: Array of arguments.
 * @av: Array of command-line arguments.
 * @env: Array of environment variables.
 */
void executeCommand(char **args, char **av, char **env)
{
	char *str1 = " : not found\n";
	char *str = ": No such file or directory\n";
	char space[] = " ";

	/*check if the path has to Handles*/
	if (args[0] != NULL && args[0][0] != '/')
	{
		if (Handle_Path(args) == 0)
		{
			write(STDOUT_FILENO, av[0], getLength(av[0]));
			write(STDOUT_FILENO, space, getLength(space));
			write(STDOUT_FILENO, args[0], getLength(args[0]));
			write(STDOUT_FILENO, str1, getLength(str1));
			args[0] = NULL;
		}
	}
	if (comp_string(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	if (execve(args[0], args, env) == -1)
	{
		write(STDOUT_FILENO, av[0], getLength(av[0]));
		write(STDOUT_FILENO, str, getLength(str));
		exit(EXIT_FAILURE);
	}
}
