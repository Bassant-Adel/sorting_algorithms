#include "sort.h"

/**
 * merge -> responsible -> merge two sub arrays -> array
 *@array: array
 *@size: size
 *@left: left
 *@right: right
 */

void merge(int *array, int *left, int *right, size_t size)
{
	int ic = 0, jc = 0, kc = 0;
	int Lx, Rx;

	Lx = size / 2;
	Rx = size - Lx;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, Lx);
	printf("[right]: ");
	print_array(right, Rx);

	while (ic < Lx && jc < Rx)
	{
		if (left[ic] < right[jc])
			array[kc++] = left[ic++];
		else
			array[kc++] = right[jc++];
	}
	while (ic < Lx)
		array[kc++] = left[ic++];
	while (jc < Rx)
	{
		array[kc++] = right[jc++];
	}	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort -> sort array
 *@array: array
 *@size: size
 */

void merge_sort(int *array, size_t size)
{
	size_t mx = 0, ic;
	int left[1000];
	int right[1000];

	if (!array)
		return;

	if (size < 2)
	{
		return;
	}	mx = size / 2;

	for (ic = 0; ic < mx; ic++)
		left[ic] = array[ic];

	for (ic = mx; ic < size; ic++)
	{
		right[ic - mx] = array[ic];
	}	merge_sort(left, mx);
	merge_sort(right, size - mx);
	merge(array, left, right, size);

}
