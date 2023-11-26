#include "sort.h"
/**
 * partition - Lomuto partition scheme for Quick Sort
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot
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
        if (i + 1 != high)
        {
                temp = array[i + 1];
                array[i + 1] = array[high];
                array[high] = temp;
                print_array(array, size);
        }
        return i + 1;
}