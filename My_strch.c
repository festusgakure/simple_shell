#include "shell.h"
/**
 * my_strchr - it finds the first occurrence of a character
 * @str: string to  be searched
 * @y:  character to be  founnd
 * Return: Pointer  occurrence of the character ,
 *          NULL if the char is not found.
 */
char *my_strchr(const char *str, char y)
{
	while (*str != '\0')
	{
		if (*str == y)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}

