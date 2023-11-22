#include "sort.h"

/**
 * counting_sort -> sort array -> int
 *@array: array
 *@size: size
 */

void counting_sort(int *array, size_t size)
{
	int xn, xj, *ax, *cut;
	size_t ix;

	if (!array || size < 2)
	{
		return;
	}	xn = array[0];
	for (ix = 0; ix < size; ix++)
	{
		if (array[ix] > xn)
			xn = array[ix];
	}	cut = calloc((xn + 1), sizeof(int));
	for (ix = 0; ix < size; ix++)
		cut[array[ix]]++;
	for (xj = 1; xj < xn; xj++)
	{
		cut[xj + 1] += cut[xj];
	}	print_array(cut, xn + 1);
	ax = malloc(sizeof(int) * size);
	for (ix = 0; ix < size; ix++)
	{
		cut[array[ix]]--;
		ax[cut[array[ix]]] = array[ix];
	}
	for (ix = 0; ix < size; ix++)
	{
		array[ix] = ax[ix];
	}	free(ax);
	free(cut);
}
