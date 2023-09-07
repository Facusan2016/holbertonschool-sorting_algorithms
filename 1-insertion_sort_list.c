# include "sort.h"

void swap_list(listint_t *curr, listint_t *next_one)
{
	listint_t *curr_prev = curr->prev;
	listint_t *next_one_next = next_one->next;

	if (curr_prev)
		(curr_prev)->next = next_one;

	(next_one)->prev = curr_prev;
	(next_one)->next = curr;
	(curr)->prev = next_one;
	(curr)->next = next_one_next;

	if (next_one_next)
		(next_one_next)->prev = curr;
}

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list;

	while (curr->next)
	{
		print_list(*list);
		while ((curr)->next && ((curr)->n > (curr)->next->n))
		{
			printf("Curr: %d, Next: %d\n", (curr)->n, (curr)->next->n);
			swap_list(curr, (curr)->next);
			curr = (curr)->prev;
		}
		curr = (curr)->next;
	}
}