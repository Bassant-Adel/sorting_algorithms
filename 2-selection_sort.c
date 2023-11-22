#include "sort.h"

/**
 * selection_sort -> sorts array
 *@array: array
 *@size: size
 */

void selection_sort(int *array, size_t size)
{
	size_t xx, xy, xz, xn;
	int aa, bb;

	if (array)
	{
		for (xx = 0; xx < size; xx++)
		{
			aa = array[xx];

			bb = 0;
			for (xy = xx; xy < size ; xy++)
			{
				if (array[xy] < aa)
				{
					xn = xy;

					aa = array[xy];

					bb = 1;
				}
			}

			if (bb == 1)
			{
				xz = array[xx];
				array[xx] = array[xn];

				array[xn] = xz;
				print_array(array, size);
			}
		}
	}
}
