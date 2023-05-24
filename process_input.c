#include "shell.h"
/**
 * processInput - Process the input string.
 * @string: Input string.
 * @args: Array to store the processed arguments.
 */
void processInput(char *string, char **args)
{
	int i = 0;

	while (string[i])
	{
		if (string[i] == '\n')
			string[i] = 0;
		i++;
	}
	args[0] = string;
}
