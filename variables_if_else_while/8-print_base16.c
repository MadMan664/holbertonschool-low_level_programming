#include <stdio.h>

/**
 * main - prints all numbers of base 16 in lowercase
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;

	i = 0;
	while (i <= 9)
	{
		putchar(i + '0');
		i++;
	}
	i = 10;
	while (i <= 15)
	{
		putchar(i - 10 + 'a');
		i++;
	}
	putchar('\n');
	return (0);
}
