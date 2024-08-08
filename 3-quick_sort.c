#include "sort.h"

/**
 * partition_array - Divides the array into two parts
 * @array: Array
 * @start: Start of the index
 * @end: End of the index
 * @size: Size of the array
 * Return: Index of the pivot after partition
 */
int partition_array(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start - 1;
	int tmp;

	for (int j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[end])
	{
		tmp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort_recursive - Recursively sorts the array
 * @array: Array
 * @start: Start of the index
 * @end: End of the index
 * @size: Size of the array
 */
void quicksort_recursive(int *array, int start, int end, size_t size)
{
	int p;

	if (start < end)
	{
		p = partition_array(array, start, end, size);
		quicksort_recursive(array, start, p - 1, size);
		quicksort_recursive(array, p + 1, end, size);
	}
}

/**
 * quick_sort - Sorts an array
 * @array: Array
 * @size: Size of the @array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quicksort_recursive(array, 0, size - 1, size);
}
