#include "shell.h"
/**
 * str_cpy - Copies a string.
 * @dst: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to  dest string.
 */
char *str_cpy(char *dst, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}

	dst[i] = '\0';

	return (dst);
}

