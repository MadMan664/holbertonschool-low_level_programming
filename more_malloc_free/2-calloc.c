#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc, and zeroes it
 * @nmemb: number of elements
 * @size: size of each element in bytes
 *
 * Return: pointer to the allocated, zeroed memory, or NULL if nmemb or
 * size is 0, or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int total, i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		ptr[i] = 0;

	return (ptr);
}
