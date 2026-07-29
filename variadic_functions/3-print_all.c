#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_char - prints a char from a va_list
 * @args: the va_list containing the char
 *
 * Return: Nothing.
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints an int from a va_list
 * @args: the va_list containing the int
 *
 * Return: Nothing.
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float from a va_list
 * @args: the va_list containing the float
 *
 * Return: Nothing.
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string from a va_list, or (nil) if NULL
 * @args: the va_list containing the string
 *
 * Return: Nothing.
 */
void print_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - prints anything, based on a format string
 * @format: list of types of arguments passed to the function
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i;
	char *sep;
	printer_t printers[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	i = 0;
	sep = "";
	va_start(args, format);
	while (format != NULL && format[i])
	{
		unsigned int j;

		j = 0;
		while (printers[j].id != '\0')
		{
			if (printers[j].id == format[i])
			{
				printf("%s", sep);
				printers[j].f(args);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
