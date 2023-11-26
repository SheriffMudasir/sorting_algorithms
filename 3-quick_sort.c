#include "sort.h"

void quick_sort_recursive(int *array, int low, int high, size_t size);

/**
 * quick_sort - This function sorts an array of integers in ascending order using Quick Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    recursive_sort(array, 0, size - 1, size);
}

/**
 * recursive_sort - This function is arecursive helper function for Quick Sort
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: The size of the array
 */
void recursive_sort(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(array, low, high, size);
        recursive_sort(array, low, pivot - 1, size);
        recursive_sort(array, pivot + 1, high, size);
    }
}

/**
 * partition - This function implements the Lomuto partition scheme for Quick Sort
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