#include "sort.h"

/**
 * swap_ints - Swaps to integers in an array.
 * @a: Integer to swap
 * @b: Integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Soorts an array of integers in ascending oder.
 * @array: The arrray to be sorted
 * @size: Number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = array + i;
		for (j = i + 1; j < size; ++j)
			min_idx = (array[j] < *min_idx) ? (array + j) : min_idx;

		if ((array + i) != min_idx)
		{
			swap_ints(array + i, min_idx);
			print_array(array, size);
		}
	}
}
