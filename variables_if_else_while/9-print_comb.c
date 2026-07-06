#include <stdio.h>

/**
 * main - prints all single-digit numbers in ascending order,
 * separated by a comma and a space
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
		if (i != 9)
		{
			putchar(',');
			putchar(' ');
		}
		i++;
	}
	putchar('\n');
	return (0);
}
