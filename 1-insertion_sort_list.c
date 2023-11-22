#include "sort.h"

/**
 * insertion_sort_list -> sorts
 *@list: list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *nn;

	if (list == NULL || (*list)->next == NULL)
	{
		return;
	}	nn = (*list)->next;

	while (nn)
	{
		while ((nn->prev) && (nn->prev->nn > nn->nn))
		{
			nn = swap_node(nn, list);
			print_list(*list);
		}		nn = nn->next;
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
	{
		now->next->prev = prev;
	}	now->next = prev;
	now->prev = prev->prev;
	prev->prev = now;

	if (now->prev)
		now->prev->next = now;
	else
	{
		*list = now;
	}	return (now);
}
