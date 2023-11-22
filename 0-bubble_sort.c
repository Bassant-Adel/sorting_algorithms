#include "sort.h"

/**
 * bubble_sort -> Sorts array of int
 *@array: It Array
 *@size: It Size
 */

void bubble_sort(int *array, size_t size)
{
	size_t byz, nxz, szz;

	for (byz = 0; byz < size; byz++)
	{
		for (nxz = 1; nxz < size - byz; nxz++)
		{
			if (array[nxz - 1] > array[nxz])
			{
				szz = array[nxz];
				array[nxz] = array[nxz - 1];

				array[nxz - 1] = szz;
				print_array(array, size);
			}
		}
	}
}
