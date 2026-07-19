#include <stdlib.h>
#include "dog.h"

/**
 * dup_str - duplicates a string into newly allocated memory
 * @str: string to duplicate, may be NULL
 *
 * Return: pointer to the duplicated string, or NULL if str is NULL
 * or malloc fails
 */
static char *dup_str(char *str)
{
	char *copy;
	unsigned int len, i;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;

	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		copy[i] = str[i];

	return (copy);
}

/**
 * new_dog - creates a new dog, storing copies of name and owner
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the newly created dog_t, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	char *name_copy, *owner_copy;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	name_copy = dup_str(name);
	if (name_copy == NULL && name != NULL)
	{
		free(d);
		return (NULL);
	}

	owner_copy = dup_str(owner);
	if (owner_copy == NULL && owner != NULL)
	{
		free(name_copy);
		free(d);
		return (NULL);
	}

	d->name = name_copy;
	d->age = age;
	d->owner = owner_copy;

	return (d);
}
