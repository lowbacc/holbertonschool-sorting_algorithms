#include "sort.h"

/**
 * knuth_seq - Find largest gap for a given size
 * @size: Size of the array
 * Return: Void
 */

size_t knuth_seq(size_t size)
{
	size_t counter;

	for (counter = 1; counter < size; counter = (counter * 3) + 1)
	{
		;
	}
	return ((counter - 1) / 3);
}


/**
 * shell_sort - Sorts an array of integers
 * @array: The array to be sorted
 * @size: Size of the array
 * Return: Void
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL || size == 0)
	{
		return;
	}

	for (gap = knuth_seq(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
