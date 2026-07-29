#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings, separated by a separator
 * @separator: string printed between strings, not printed if NULL
 * @n: the number of strings passed to the function
 *
 * Return: Nothing.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *str;
	va_list args;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);
		if (str == NULL)
			printf("(nil)");
		if (str != NULL)
			printf("%s", str);
		if (separator != NULL && i != n - 1)
			printf("%s", separator);
	}
	va_end(args);
	printf("\n");
}
