#include "sort.h"
/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 *              with Lomuto partition scheme.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quick_sort_helper(array, 0, size - 1, size);
}
/**
 * quick_sort_helper - Helper function for quick_sort
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_idx = partition(array, low, high, size);
quick_sort_helper(array, low, pivot_idx - 1, size);
quick_sort_helper(array, pivot_idx + 1, high, size);
}
}
/**
 * partition - Lomuto partition scheme for Quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Number of elements in the array
 * Return: Index of the pivot element after partition
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j, temp;
for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}
}
if ((i + 1) != high)
{
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
}
return (i + 1);
}
