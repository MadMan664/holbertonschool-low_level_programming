#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int i, j, product;

	i = 0;
	while (i <= 9)
	{
		j = 0;
		while (j <= 9)
		{
			product = i * j;
			if (j == 0)
			{
				_putchar(product + '0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				if (product < 10)
				{
					_putchar(' ');
				}
				else
				{
					_putchar(product / 10 + '0');
				}
				_putchar(product % 10 + '0');
			}
			j++;
		}
		_putchar('\n');
		i++;
	}
}
