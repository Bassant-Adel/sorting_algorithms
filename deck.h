#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * enum kind_e -> list -> card
 *@SPADE: Spade
 *@HEART: Heart
 *@CLUB: Club
 *@DIAMOND: Diamond
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Play card
 *@value: Value
 *From "Ace" to "King"
 *@kind: Kind of card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s -> deck -> card
 *@card: Pointer -> card of node
 *@prev: Pointer -> previous node of list
 *@next: Pointer -> next node of list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

char get_valud(deck_node_t *card);

void sort_deck(deck_node_t **deck);

int _strcmp(const char *s3, const char *s4);

void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);

#endif
