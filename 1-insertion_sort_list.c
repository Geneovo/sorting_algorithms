#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list
 * of integers in ascending order using the for insertion sort algorithm
 *
 * @list: A pointer to the head of the doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *new = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	new = *list;
	new = new->next;

	while (new)
	{
		while (new->prev && new->n < (new->prev)->n)
		{
			tmp = new;

			if (new->next)
				(new->next)->prev = tmp->prev;
			(new->prev)->next = tmp->next;
			new = new->prev;
			tmp->prev = new->prev;
			tmp->next = new;

			if (new->prev)
				(new->prev)->next = tmp;
			new->prev = tmp;

			if (tmp->prev == NULL)
				*list = tmp;
			print_list(*list);
			new = new->prev;
		}
		new = new->next;
	}
}
