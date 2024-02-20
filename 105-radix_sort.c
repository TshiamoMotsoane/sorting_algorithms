#include "sort.h"

/**
 * getMax - Get the maximum value in the array
 * @array: The array of integers
 * @size: Number of elements in the array
 * Return: The maximum value in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countingSort - Perform counting sort based on the significant digit
 * @array: The array of integers
 * @size: Number of elements in the array
 * @exp: The current significant digit
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using Radix sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	size_t exp;

	if (array == NULL || size < 2)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
		countingSort(array, size, exp);
}
