#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @a: First node to swap
 * @b: Second to swap
 */

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *prev = a->prev;
	listint_t *next = b->next;

	if (prev)
		prev->next = b;
	else
		*list = b;
	if (next)
		next->prev = a;
	b->prev = prev;
	b->next = a;
	a->prev = b;
	a->next = next;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * @list: Pointer to the head of the list
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *curr;

	if (!list || !*list)
		return;

	while (swapped)
	{
		swapped = 0;
		curr = *list;
		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				swapped = 1;
				print_list(*list);
			}
			else
				curr = curr->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		curr = curr->prev;
		while (curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				swapped = 1;
				print_list(*list);
			}
			else
				curr = curr->prev;
		}
	}
}
