#include "shell.h"
/**
 * prompt - Shell prompt to take user inputs and execute commands.
 * @env: Array of environment variables.
 * @av: Array of command-line arguments.
 */

void prompt(char **av, char **env)
{
	ssize_t wordst;
	char *string = NULL;
	size_t n = 0;
	pid_t fpid;
	char *args[] = {"NULL", NULL};
	#define MAX_COM 10
	int wstatus;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			ssize_t ret;
			ret = write(STDOUT_FILENO, "#cisfun$ ", getLength("#cisfun$ "));
			if (ret == -1) {
				exit(EXIT_FAILURE);
			}
		}
		wordst = getline(&string, &n, stdin);
		if (wordst == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (wordst == 1)
		{
			continue; /*Skip the rest of the loop and prompt again*/
		}
		processInput(string, args);
		if (comp_string(args[0], "exit") == 0)
		{
			free(string);
			exit(EXIT_SUCCESS);
		}
		executeCommand(args, av, env);
		
	}
}

