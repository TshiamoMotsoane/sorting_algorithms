#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending oder
 * using the Counting sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i, max, total;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > (int)max)
			max = array[i];

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
	{
		free(count);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	total = 0;
	for (i = 0; i <= max; i++)
	{
		total += count[i];
		count[i] = total;
	}
	print_array(count, max + 1);
	output = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
