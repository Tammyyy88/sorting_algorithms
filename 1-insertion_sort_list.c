#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *                       ascending order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *prev, *next;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
current = (*list)->next;
while (current)
{
prev = current->prev;
next = current->next;
while (prev && current->n < prev->n)
{
if (next)
next->prev = prev;
prev->next = next;
current->prev = prev->prev;
if (prev->prev)
prev->prev->next = current;
else
*list = current;
prev->prev = current;
current->next = prev;
print_list(*list);
prev = current->prev;
next = current->next;
}
current = next;
}
}
