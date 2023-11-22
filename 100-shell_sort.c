#include "sort.h"

/**
 * swap_2_ints - swap twoo int -> array
 *@a: int
 *@b: next int
 */

void swap_2_ints(int *a, int *b)
{
	int zu;

	zu = *a;

	*a = *b;

	*b = zu;
}

/**
 * shell_sort -> sorts array -> int
 *@array: array
 *@size: size
 */

void shell_sort(int *array, size_t size)
{
	size_t gp, zs, dz;

	if (array == NULL || size < 2)
	{
		return;
	}	gp = 1;

	while (gp < (size / 3))
		gp = gp * 3 + 1;

	while (gp >= 1)
	{
		zs = gp;

		while (zs < size)
		{
			dz = zs;

			while (dz >= gp && array[dz - gp] > array[dz])
			{
				swap_2_ints(array + dz, array + (dz - gp));
				dz -= gp;
			}			zs++;
		}		gp /= 3;
		print_array(array, size);
	}
}
