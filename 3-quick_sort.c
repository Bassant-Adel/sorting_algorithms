#include "sort.h"

/**
 * quick_sort_rec -> sorts array
 *@array: array
 *@size: size
 *@array_init: arry initi
 *@size_init: size Initi
 */

void quick_sort_rec(int *array_init, size_t size_init, int *array, size_t size)
{
	size_t ay, aa;
	int ab;
	int ai = -1, an, ap = array[size - 1];

	if (array && size > 1)
	{
		for (ay = 0; ay < size - 1; ay++)
		{
			if (array[ay] < ap)
			{
				ai++;
				aa = ai;

				if (aa != ay && array[ay] != array[aa])
				{
					an = array[ay];
					array[ay] = array[ai];
					array[ai] = an;
					print_array(array_init, size_init);
				}
			}
		}		ab = size;

		if (ab - 1 != ai + 1 && array[ab - 1] != array[ai + 1])
		{
			array[size - 1] = array[ai + 1];
			array[ai + 1] = ap;
			print_array(array_init, size_init);
		}

		if (ai > 0)
			quick_sort_rec(array_init, size_init, array, ai + 1);
		quick_sort_rec(array_init, size_init, array + ai + 2,  size - (ai + 2));
	}
}

/**
 * quick_sort -> sort array
 *@array: array
 *@size: size
 */

void quick_sort(int *array, size_t size)
{

	int *_arr;
	size_t _sai;

	if (array)
	{
		_arr = array;

		_sai = size;

		quick_sort_rec(_arr, _sai, array, size);
	}
}
