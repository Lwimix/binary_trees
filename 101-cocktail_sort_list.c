#include "sort.h"

/**
 * cocktail_sort_list - implements cocktail sorting algorithm
 * @list: unsorted/sorted list
 *
 * Return: nothing
 */
void swaps(listint_t **head, listint_t *one, listint_t *two);
void cocktail_sort_list(listint_t **list)
{
	listint_t *mycurr = NULL, *mynext = NULL;
	int swapping = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapping = 0;
		mycurr = *list;
		while (mycurr->next != NULL && mycurr != NULL)
		{
			if (mycurr->n > mycurr->next->n)
			{
				mynext = mycurr->next;
				swaps(list, mycurr, mynext);
				print_list(*list);
				swapping = 1;
			}
			else
				mycurr = mycurr->next;
		}
		if (swapping == 0)
			break;
		swapping = 0;
		mycurr = mycurr->next;
		while (mycurr != NULL && mycurr->prev != NULL)
		{
			mynext = mycurr->prev;
			if (mycurr->n < mycurr->prev->n)
			{
				swaps(list, mycurr, mynext);
				print_list(*list);
				swapping = 1;
			}
			else
				mycurr = mycurr->prev;
		}

	} while (swapping);
}

void swaps(listint_t **head, listint_t *one, listint_t *two)
{
	listint_t *temp_n = NULL, *temp_p = NULL;

	if (one == NULL || two == NULL || one == two)
	        return;
	if (one->prev != NULL)
		one->prev->next = two;
	else
		*head = two;
	if (two->prev != NULL)
		two->prev->next = one;
	else
		*head = one;
	temp_n = one->next;
	one->next = two->next;
	two->next = temp_n;
	if (one->next != NULL)
		one->next->prev = one;
	if (two->next != NULL)
		two->next->prev = two;
	temp_p = one->prev;
	one->prev = two->prev;
	two->prev = temp_p;
}
