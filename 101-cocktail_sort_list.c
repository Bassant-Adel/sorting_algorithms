#include "sort.h"

/**
 * swap1 -> responsible -> swap two nodes
 *@list: list
 *@head: head Node
 *@aux: auxiliary node
 */

void swap1(listint_t **list, listint_t *head, listint_t *aux)
{
	if (head->prev)
		head->prev->next = aux;

	else
		*list = aux;

	if (aux->next)
	{
		aux->next->prev = head;
	}	head->next = aux->next;
	aux->prev = head->prev;
	aux->next = head;

	head->prev = aux;
	print_list(*list);
}

/**
 * swap2 -> responsible -> swap two nodes
 *@list: list
 *@head: head Node
 *@aux: auxiliary Node
 */

void swap2(listint_t **list, listint_t *head, listint_t *aux)
{
	aux = head->prev;
	aux->next->prev = aux->prev;

	if (aux->prev)
		aux->prev->next = aux->next;

	else
	{
		*list = aux->next;

	}	aux->prev = aux->next;
	aux->next = aux->next->next;
	aux->prev->next = aux;

	if (aux->next)
	{
		aux->next->prev = aux;
	}	print_list(*list);
}

/**
 * cocktail_sort_list -> sort cockks
 *@list: list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *zh, *az;
	int bx = 1;

	if (list)
	{
		zh = *list;
		while (bx != 0)
		{
			bx = 0;
			while (zh->next)
			{
				if (zh->n > zh->next->n)
				{
					az = zh->next;
					swap1(list, zh, az);
					bx = 1;
				}
				else
					zh = zh->next;
			}

			if (bx == 0)
			{
				break;
			}			bx = 0;
			while (zh->prev)
			{
				if (zh->prev->n > zh->n)
				{
					swap2(list, zh, az);
					bx = 1;
				}
				else
					zh = zh->prev;
			}
		}
	}
}
