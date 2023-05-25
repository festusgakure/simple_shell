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

	if (args[0] != NULL && args[0][0] != '/')
	{
		if (Handle_Path(args) == 0)
		{
			ssize_t ret;
			ret = write(STDOUT_FILENO, av[0], getLength(av[0]));
			if (ret == -1) {
				exit(EXIT_FAILURE);
			}
			ret = write(STDOUT_FILENO, space, getLength(space));
			if (ret == -1) {
				exit(EXIT_FAILURE);
			}
			ret = write(STDOUT_FILENO, args[0], getLength(args[0]));
			if (ret == -1)
			{
				exit(EXIT_FAILURE);
			}
			ret = write(STDOUT_FILENO, str1, getLength(str1));
			if (ret == -1)
			{
				exit(EXIT_FAILURE);
			}
			args[0] = NULL;
        }
    }
    if (comp_string(args[0], "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }

    pid_t fpid;
    int wstatus;

    fpid = fork();
    if (fpid == -1)
    {
        exit(EXIT_FAILURE);
    }
    if (fpid == 0)
    {
        if (execve(args[0], args, env) == -1)
        {
            ssize_t ret;

            ret = write(STDOUT_FILENO, av[0], getLength(av[0]));
            if (ret == -1) {
                exit(EXIT_FAILURE);
            }

            ret = write(STDOUT_FILENO, str, getLength(str));
            if (ret == -1) {
                exit(EXIT_FAILURE);
            }

            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&wstatus);
    }
}

