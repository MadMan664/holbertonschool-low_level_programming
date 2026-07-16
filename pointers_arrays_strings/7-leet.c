#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: the string to encode
 *
 * Return: a pointer to str
 */
char *leet(char *str)
{
	char search[] = "aAeEoOtTlL";
	char replace[] = "4433007711";
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (search[j] != '\0')
		{
			if (str[i] == search[j])
				str[i] = replace[j];
			j++;
		}
		i++;
	}
	return (str);
}
