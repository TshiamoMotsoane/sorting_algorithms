#include "sort.h"

/**
 * merge - merges two sorted subarrays into one sorted array
 * @array: pointer to the array to sort
 * @left: pointer to the left subarray
 * @right: pointer to the right subarray
 * @size: size of the array
 */
void merge(int *array, int *left, int *right, size_t size)
{
	size_t i = 0, j = 0, k = 0;
	size_t left_size = size / 2;
	size_t right_size = size - left_size;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < left_size)
		array[k++] = left[i++];
	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - sorts an array of integers in ascending oder
 * using the top-down merge sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i = 0;
	int *left = NULL, *right = NULL;

	if (!array || size < 2)
		return;

	mid = size / 2;

	left = malloc(sizeof(int) * mid);
	if (!left)
		return;

	right = malloc(sizeof(int) * (size - mid));
	if (!right)
	{
		free(left);
		return;
	}
	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);

	free(left);
	free(right);
}
