#include <stdio.h>

/**
 * main - prints all single digit numbers of base 10, no char variables
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
	putchar('\n');
	return (0);
}
