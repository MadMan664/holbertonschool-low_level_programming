#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2D array of integers, each
 * initialized to 0
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to the newly allocated grid, or NULL on failure
 * or if width or height is 0 or negative
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int h, w;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	for (h = 0; h < height; h++)
	{
		grid[h] = malloc(sizeof(int) * width);
		if (grid[h] == NULL)
		{
			for (w = 0; w < h; w++)
				free(grid[w]);
			free(grid);
			return (NULL);
		}
		for (w = 0; w < width; w++)
			grid[h][w] = 0;
	}

	return (grid);
}
