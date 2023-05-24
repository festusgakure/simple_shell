/**
 * str_cat - Concatenates two strings.
 * @dst: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to the destination string.
 */
char *str_cat(char *dst, const char *src)
{
	int dst_ln = 0;
	int i = 0;

	while (dst[dst_ln] != '\0')
		dst_ln++;

	while (src[i] != '\0')
	{
		dst[dst_ln] = src[i];
		dst_ln++;
		i++;
	}

	dst[dst_ln] = '\0';

	return (dst);
}

