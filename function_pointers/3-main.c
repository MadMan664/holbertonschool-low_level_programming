#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - performs a simple operation on two integers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exits with an error status on failure
 */
int main(int argc, char *argv[])
{
	int a, b, result;
	int (*f)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	f = get_op_func(argv[2]);
	if (!f)
	{
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	if ((*argv[2] == '/' || *argv[2] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = f(a, b);
	printf("%d\n", result);
	return (0);
}
