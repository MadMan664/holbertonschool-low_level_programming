#include <stdio.h>

/**
 * main - prints the lowercase alphabet followed by a new line
 *
 * Return: Always 0.
 */
int main(void)
{
	char c;

	c = 'a';
	while (c <= 'z')
	{
		putchar(c);
		c++;
	}
	putchar('\n');
	return (0);
}
