#include "sort.h"

/**
 * max_val -> max vaal
 *@array: array
 *@size: size
 *Return: Max
 */

int max_val(int *array, size_t size)
{
	int maxx = array[0];
	size_t xi;

	for (xi = 0; xi < size; xi++)
	{
		if (array[xi] > maxx)
			maxx = array[xi];
	}	return (maxx);
}

/**
 * radix_sort -> sort array
 *@array: array
 *@size: size
 */

void radix_sort(int *array, size_t size)
{
	int *new;
	int ni, mx, ny = 1;
	int nq = size;

	if (!array || size < 2)
	{
		return;
	}	mx = max_val(array, size);
	new = malloc(sizeof(int) * size);
	while (mx / ny > 0)
	{
		int brews[20] = {0};

		ni = 0;
		while (ni < nq)
		{
			brews[(array[ni] / ny) % 10]++;
			ni++;
		}
		if (brews != NULL)
		{
			for (ni = 1; ni < 10; ni++)
				brews[ni] += brews[ni - 1];
			for (ni = nq - 1; ni >= 0; ni--)
			{
				new[brews[(array[ni] / ny) % 10] - 1] = array[ni];
				brews[(array[ni] / ny) % 10]--;
			}
			for (ni = 0; ni < nq; ni++)
				array[ni] = new[ni];

		}		ny *= 10;
		print_array(array, size);

	}	free(new);
}
