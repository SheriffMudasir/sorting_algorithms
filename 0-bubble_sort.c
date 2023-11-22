#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - This function sorts an array of integers
 *
 * @array: Array of integers to be sorted
 * @size: Number of integers in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;
	int swap_count;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		swap_count = 0;

		for (j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swap_count = 1;
				print_array(array, size);
			}
		}

		if (swap_count == 0)
			break;
	}
}
