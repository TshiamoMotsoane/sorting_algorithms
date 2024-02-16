#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: int to be swapped
 * @b: int to be swapped
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending oder.
 * @array: The array to be sorted,
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j = size;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	while (swapped == false)
	{
		swapped = true;
		for (i = 0; i < j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				swapped = false;
			}
		}
		j--;
	}
}
