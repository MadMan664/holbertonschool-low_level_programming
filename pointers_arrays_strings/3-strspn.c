#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to check
 * @accept: the string of bytes to match
 *
 * Return: the number of bytes in the initial segment of s which
 *         consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	unsigned int i;
	int found;

	count = 0;
	while (s[count] != '\0')
	{
		found = 0;
		i = 0;
		while (accept[i] != '\0')
		{
			if (s[count] == accept[i])
				found = 1;
			i++;
		}
		if (found == 0)
			break;
		count++;
	}
	return (count);
}
