#include "main.h"

/**
 * _strncpy - copies at most n bytes from src to dest
 * @dest: the destination buffer
 * @src: the source string
 * @n: the maximum number of bytes to copy
 *
 * Return: a pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
