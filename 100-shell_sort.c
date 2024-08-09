#include "sort.h"

/**
 *shell_sort - sorts an array of integers in ascending order
 *using the Shell sort algorithm, using the Knuth sequence
 *@array: the array
 *@size: the size
 *
 *Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t h = 1, i, n;
	int number;

	if (array == NULL || size < 2)
		return;

	while (h < size / 3)
	{
		h = h * 3 + 1;
	}

	for (; h >= 1; h /= 3)
	{
		for (i = h; i < size; i++)
		{
			n = i;
			while (n >= h && array[n] < array[n - h])
			{
				number = array[n];
				array[n] = array[n - h];
				array[n - h] = number;
				n -= h;
			}
		}
		print_array(array, size);
	}
}
