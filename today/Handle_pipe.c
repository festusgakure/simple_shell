#include "shell.h"


/**
 * Handle_Pipe - Includes pipe arguments to path.
 * @arg: The command argument containing the pipe symbol.
 * Return: The modified command path with pipe arguments.
 */

char *Handle_Pipe(char *arg)
{
	char *cmnd = strtok(arg, "|");
	char *arg_str = strtok(NULL, "|");
	char *trimmed_args = arg_str;
	size_t len;
	char *modified_path;

	while (*trimmed_args == ' ')
		trimmed_args++;

	len = getLength(trimmed_args);

	while (len > 0 && trimmed_args[len - 1] == ' ')
		trimmed_args[--len] = '\0';

	modified_path = malloc(getLength(cmnd) + getLength(trimmed_args) + 4);

		if (modified_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

	str_cpy(modified_path, cmnd);
	str_cat(modified_path, " | ");
	str_cat(modified_path, trimmed_args);

	return (modified_path);
}

