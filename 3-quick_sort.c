#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

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
	int pivot, i, j;

	pivot = array[end];
	i = start;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		swap(&array[i], &array[end]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort_recursive - Recursively sorts the array
 * @array: Array
 * @start: Start of the index
 * @end: End of the index
 * @size: Size of the array
 * Return: void
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
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
