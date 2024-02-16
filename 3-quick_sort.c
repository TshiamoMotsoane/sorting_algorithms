#include "sort.h"

void swap_ints(int *a, int *b);
int partition(int *array, int low, int high, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
/**
 * swap_ints - Swaps two integers in an array.
 * @a: Integer to be swapped.
 * @b: Ineger to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Partitions the array using the lomuto partition scheme
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 * Return: Index of the pivot after partitioning
 */
int partition(int *array, int low, int high, size_t size)
{
	int *pivot, left, right;

	pivot = array + high;
	for (right = left = low; left < high; left++)
	{
		if (array[left] < *pivot)
		{
			if (right < left)
			{
				swap_ints(array + left, array + right);
				print_array(array, size);
			}
			right++;
		}
	}
	if (array[right] > *pivot)
	{
		swap_ints(array + right, pivot);
		print_array(array, size);
	}

	return (right);
}
/**
 * quicksort_recursive - Recursively sorts the array using quicksort
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (high - low > 0)
	{
		pi = partition(array, low, high, size);
		quicksort_recursive(array, low, pi - 1, size);
		quicksort_recursive(array, pi + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending oder.
 * @array: The array to be sorted
 * @size:  Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
