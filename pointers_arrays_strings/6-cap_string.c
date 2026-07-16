#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: the string to modify
 *
 * Return: a pointer to str
 */
char *cap_string(char *str)
{
	char separators[] = " \t\n,;.!?\"(){}";
	int i;
	int j;
	int prev_is_sep;

	i = 0;
	prev_is_sep = 1;
	while (str[i] != '\0')
	{
		j = 0;
		if (prev_is_sep && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		prev_is_sep = 0;
		while (separators[j] != '\0')
		{
			if (str[i] == separators[j])
				prev_is_sep = 1;
			j++;
		}
		i++;
	}
	return (str);
}
