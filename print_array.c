#include <stdlib.h>
#include <stdio.h>

/**
 * print_array -> Print array integers
 *@array: array -> be printed
 *@size: size
 */

void print_array(const int *array, size_t size)
{
	size_t vi;

	vi = 0;

	while (array && vi < size)
	{
		if (vi > 0)
		{
			printf(", ");
		}		printf("%d", array[vi]);
		++vi;

	}	printf("\n");
}
