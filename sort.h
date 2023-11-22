#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * struct listint_s -> list node
 *@n: Int stored in node
 *@prev: Pointer previous element of list
 *@next: Pointer next element of list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);

void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);

void bitonic_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

void print_array(const int *array, size_t size);

listint_t *swap_node(listint_t *node, listint_t **list);

#endif
