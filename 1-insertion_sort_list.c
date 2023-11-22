#include "sort.h"

/**
 * insertion_sort_list -> sorts
 *@list: list
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *n;

	if (list == NULL || (*list)->next == NULL)
	{
		return;
	}	n = (*list)->next;

	while (n)
	{
		while ((n->prev) && (n->prev->n > n->n))
		{
			n = swap_node(n, list);
			print_list(*list);
		}		n = n->next;
	}
}

/**
 * swap_node -> SWAPS 2 Nodes
 *@node: node
 *@list: list
 *Return: node
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{

	listint_t *prev = node->prev, *now = node;

	prev->next = now->next;

	if (now->next)
		now->next->prev = prev;
	now->next = prev;
	now->prev = prev->prev;
	prev->prev = now;

	if (now->prev)
		now->prev->next = now;
	else
	{
		*list = now;
	}	return (now);
}
