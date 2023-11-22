#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - This function sorts an array of integers
 *
 * @array: The array of integers to be sorted
 * @size: Number of elements in array
 */
void selection_sort(int *array, size_t size)
{
        size_t i;
	size_t j;
	size_t index;
        int swap;

        if (array == NULL || size < 2)
                return;

        for (i = 0; i < size - 1; ++i)
        {
                index = i;

                for (j = i + 1; j < size; ++j)
                {
                        if (array[j] < array[index])
                                index = j;
                }

                if (index != i)
                {
                        swap = array[i];
                        array[i] = array[index];
                        array[index] = swap;

                        print_array(array, size);
                }
        }
}
