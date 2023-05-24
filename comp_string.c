/**
 * comp_string - Compare two strings without using strcmp.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: 0 if  equal, -1 if str1 is less than str2,
 * 1 if str1 is greater than str2.
 */
int comp_string(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 == *str2)
	{
		return (0); /* Strings are equal */
	}
	else if (*str1 < *str2)
	{
		return (-1); /* str1 is less than str2 */
	}
	else
	{
		return (1); /* str1 is greater than str2 */
	}
}
