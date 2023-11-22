#include "deck.h"

/**
 * _strcmp -> (TWO) str comparisons
 *@s3: first str
 *@s4: second str
 *Return: success -> (0)
 */

int _strcmp(const char *s3, const char *s4)
{

	for (; *s3 && *s4 && *s3 == *s4; s3++, s4++)
	{
	}

	if (*s3 != *s4)
	{

		return (*s3 - *s4);

	}	return (0);

}


/**
 * get_value -> Obtain card's numerical
 *@card: card pointer
 *Return: card's numerical
 */

char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);

	if (_strcmp(card->card->value, "1") == 0)
		return (1);

	if (_strcmp(card->card->value, "2") == 0)
		return (2);

	if (_strcmp(card->card->value, "3") == 0)
		return (3);

	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
	{
		return (7);
	}
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
	{
		return (12);
	}	return (13);
}

/**
 * insertion_sort_deck_kind -> spades -> diamonds
 *@deck: pointer deck
 */

void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *itl, *inrt, *tp;

	itl = (*deck)->next;

	while (itl != NULL)
	{
		tp = itl->next;
		inrt = itl->prev;

		while (inrt != NULL && inrt->card->kind > itl->card->kind)
		{
			inrt->next = itl->next;

			if (itl->next != NULL)
			{
				itl->next->prev = inrt;
			}			itl->prev = inrt->prev;
			itl->next = inrt;

			if (inrt->prev != NULL)
				inrt->prev->next = itl;
			else
			{
				*deck = itl;
			}			inrt->prev = itl;
			inrt = itl->prev;
		}		itl = tp;
	}
}


/**
 * insertion_sort_deck_value -> sort deck -> cards
 *@deck: pointer deckk
 */

void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *itl, *inrt, *tp;

	itl = (*deck)->next;

	while (itl != NULL)
	{
		tp = itl->next;
		inrt = itl->prev;
		while (inrt != NULL && inrt->card->kind == itl->card->kind &&
				get_value(inrt) > get_value(itl))
		{
			inrt->next = itl->next;

			if (itl->next != NULL)
			{
				itl->next->prev = inrt;
			}			itl->prev = inrt->prev;
			itl->next = inrt;

			if (inrt->prev != NULL)
				inrt->prev->next = itl;
			else
			{
				*deck = itl;
			}			inrt->prev = itl;
			inrt = itl->prev;
		}		itl = tp;
	}
}


/**
 * sort_deck -> sort cards -> deck -> ace -> king
 *@deck: pointer deckk
 */

void sort_deck(deck_node_t **deck)
{

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
	{

		return;

	}	insertion_sort_deck_kind(deck);

	insertion_sort_deck_value(deck);

}
