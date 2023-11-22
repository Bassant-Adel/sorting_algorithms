#include "sort.h"

/**
 * swap -> swap two elements
 *@array: array
 *@item1: Item 1
 *@item2: Item 2
 */

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int mb;

	mb = array[item1];
	array[item1] = array[item2];
	array[item2] = mb;
}

/**
 * hoare_partition -> implementing
 *@array: array
 *@first: Element 1
 *@last: last
 *@size: size
 *Return: Value
 */

int hoare_partition(int *array, int first, int last, int size)
{
	int aa = first - 1, b = last + 1;
	int ap = array[last];

	while (1)
	{
		do {
			aa++;
		} while (array[aa] < ap);

		do {
			b--;
		} while (array[b] > ap);

		if (aa >= b)
		{
			return (aa);
		}		swap(array, aa, b);
		print_array(array, size);
	}
}

/**
 * quick_ssort -> quick Sort
 *@array: array
 *@first: element (1)
 *@last: element (2)
 *@size: Array -> size
 */

void quick_ssort(int *array, ssize_t first, ssize_t last, int size)
{

	ssize_t bb = 0;

	if (first < last)
	{
		bb = hoare_partition(array, first, last, size);

		quick_ssort(array, first, bb - 1, size);

		quick_ssort(array, bb, last, size);
	}
}

/**
 * quick_sort_hoare -> sort array
 *@array: array
 *@size: size
 */

void quick_sort_hoare(int *array, size_t size)
{

	if (!array || size < 2)
	{
		return;
	}	quick_ssort(array, 0, size - 1, size);
}
