#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings, using at most n bytes of s2
 * @s1: first string (treated as empty if NULL)
 * @s2: second string (treated as empty if NULL)
 * @n: maximum number of bytes of s2 to use
 *
 * Return: pointer to the newly allocated, concatenated, null-terminated
 * string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int len1, len2, i, j;

	len1 = 0;
	len2 = 0;

	if (s1 != NULL)
		while (s1[len1] != '\0')
			len1++;

	if (s2 != NULL)
		while (s2[len2] != '\0')
			len2++;

	if (n >= len2)
		n = len2;

	result = malloc(sizeof(char) * (len1 + n + 1));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	for (j = 0; j < n; j++)
		result[len1 + j] = s2[j];

	result[len1 + n] = '\0';

	return (result);
}
