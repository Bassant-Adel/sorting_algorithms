#include <stdio.h>
#include "sort.h"

/**
 * print_list -> Print list -> integers
 *@list: list
 */

void print_list(const listint_t *list)
{
	int iv;

	iv = 0;

	while (list)
	{
		if (iv > 0)
		{
			printf(", ");

		}		printf("%d", list->n);
		++iv;
		list = list->next;

	}	printf("\n");
}
