#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers,
 *               followed by a new line
 * @a: the array of integers
 * @n: the number of elements to print
 */
void print_array(int *a, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (i == n - 1)
			printf("%d", a[i]);
		else
			printf("%d, ", a[i]);
		i++;
	}
	printf("\n");
}
