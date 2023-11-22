#include "sort.h"

/**
 * swap -> swap two elements
 *@arr: It array
 *@item1: Item 1
 *@item2: Item 2
 *@order: order
 */

void swap(int arr[], int item1, int item2, int order)
{
	int ab;

	if (order == (arr[item1] > arr[item2]))
	{
		ab = arr[item1];

		arr[item1] = arr[item2];
		arr[item2] = ab;
	}
}

/**
 * merge -> Sort array
 *@arr: array
 *@low: low
 *@n_elemnt: n element
 *@order: order
 */

void merge(int arr[], int low, int n_elemnt, int order)
{
	int h, hi;

	if (n_elemnt > 1)
	{
		h = n_elemnt / 2;

		for (hi = low; hi < low + h; hi++)
		{
			swap(arr, hi, hi + h, order);
		}		merge(arr, low, h, order);
		merge(arr, low + h, h, order);
	}
}

/**
 * ssort_bitonic ->  Sort array
 *@arr: array
 *@low: low
 *@n_elemnt: n element
 *@order: order
 *@size: size
 */

void ssort_bitonic(int arr[], int low, int n_elemnt, int order, int size)
{
	int k;

	if (n_elemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", n_elemnt, size);
			print_array(&arr[low], n_elemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", n_elemnt, size);
			print_array(&arr[low], n_elemnt);
		}		k = n_elemnt / 2;
		ssort_bitonic(arr, low, k, 1, size);
		ssort_bitonic(arr, low + k, k, 0, size);
		merge(arr, low, n_elemnt, order);

		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", n_elemnt, size);
			print_array(&arr[low], n_elemnt);
		}

		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", n_elemnt, size);
			print_array(&arr[low], n_elemnt);
		}
	}
}

/**
 * bitonic_sort -> sort array
 *@array: array
 *@size: size
 */

void bitonic_sort(int *array, size_t size)
{
	int ordr = 1;

	if (!array || size < 2)
	{
		return;

	}	ssort_bitonic(array, 0, size, ordr, size);
}
