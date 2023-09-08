# include "sort.h"

/**
 * swap_list - swap two adjacent nodes in a doubly linked list
 * @curr: pointer to the current node to be swapped
 * @prev_one: pointer to the previous node before curr
 */
void swap_list(listint_t *curr, listint_t *prev_one)
{
	if (prev_one)
		(prev_one)->next = (curr)->next;
	if ((curr)->next)
		(curr)->next->prev = prev_one;
	if (prev_one && (prev_one)->prev)
		(prev_one)->prev->next = curr;
	if ((curr)->prev)
		(curr)->prev = (prev_one)->prev;
	(prev_one)->prev = curr;
	(curr)->next = prev_one;
}

/**
 * insertion_sort_list - sort a doubly linked list using insertion sort
 * @list: pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;

	while (curr)
	{
		while ((curr)->prev && ((curr)->n < (curr)->prev->n))
		{
			swap_list(curr, (curr)->prev);
			if (!(curr)->prev)
				*list = curr;
			print_list(*list);
		}
		curr = (curr)->next;
	}
}
