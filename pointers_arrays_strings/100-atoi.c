#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the converted integer, or 0 if no digits are found
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int result;
	int started;

	i = 0;
	sign = 1;
	result = 0;
	started = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-' && started == 0)
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			result = (result * 10) - (s[i] - '0');
		}
		else if (started == 1)
		{
			break;
		}
		i++;
	}
	if (sign == 1)
		result *= -1;
	return (result);
}
