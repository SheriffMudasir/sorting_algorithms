#include "sort.h"
#include <stdio.h>
#include <stddef.h>
/**
 * insertion_sort_list - This function orts a doubly linked list of integers
 *
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
        listint_t *current;
	listint_t *temp;

        if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL)
                return;

        current = (*list)->next;

        while (current != NULL)
        {
                temp = current;

                while (temp->prev != NULL && temp->n < temp->prev->n)
                {
                        if (temp->next != NULL)
                                temp->next->prev = temp->prev;
                        temp->prev->next = temp->next;
                        temp->next = temp->prev;
                        temp->prev = temp->prev->prev;
                        temp->next->prev = temp;

                        if (temp->prev != NULL)
                                temp->prev->next = temp;

                        if (temp->prev == NULL)
                                *list = temp;

                        print_list(*list);
                }

                current = current->next;
        }
}
