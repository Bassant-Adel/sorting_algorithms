#include "sort.h"

/**
 * check_tree -> check & maintain
 *@array: array
 *@size: size
 *@size_init: size initi
 *@i: i
 */

void check_tree(int *array, size_t size_init, size_t size, size_t i)
{
	int nx, bx1, bx2;
	size_t a1, a2;

	a1 = i * 2 + 1;
	a2 = a1 + 1;
	bx1 = array[a1];
	bx2 = array[a2];

	if (((a1 < size) && (a2 < size) && (bx1 >= bx2 && bx1 > array[i]))
		|| ((a1 == size - 1) && bx1 > array[i]))
	{
		nx = array[i];
		array[i] = bx1;
		array[a1] = nx;
		print_array(array, size_init);
	}
	else if ((a1 < size) && (a2 < size) && (bx2 > bx1 && bx2 > array[i]))
	{
		nx = array[i];
		array[i] = bx2;
		array[a2] = nx;
		print_array(array, size_init);
	}
	if (a1 < size - 1)
		check_tree(array, size_init, size, a1);
	if (a2 < size - 1)
		check_tree(array, size_init, size, a2);
}

/**
 * heap_sort -> sort array
 *@array: array
 *@size: size
 */

void heap_sort(int *array, size_t size)
{
	size_t xx, size_init = size;
	int xn;

	if (!array)
		retur;
	for (xx = 0; xx < size / 2 ; xx++)
		check_tree(array, size_init, size, size / 2 - 1 - xx);

	for (xx = 0; xx < size_init - 1; xx++)
	{
		xn = array[0];
		array[0] = array[size - 1 - xx];
		array[size - 1 - xx] = xn;
		print_array(array, size_init);
		check_tree(array, size_init, size - xx - 1, 0);
	}
}
