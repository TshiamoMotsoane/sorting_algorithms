#include "sort.h"

/**
 * sift_down - Sift down a node int the heap to maintain heap property
 * @array: The array representing the heap
 * @size:  Size of the heap
 * @root: Index of the root of the subtree to sift down
 * @end: Index of the last element in the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t max_child, left_child;
	int temp;

	while ((left_child = 2 * root + 1) <= end)
	{
		max_child = left_child;
		if (left_child < end && array[left_child] < array[left_child + 1])
			max_child++;

		if (array[root] >= array[max_child])
			return;

		temp = array[root];
		array[root] = array[max_child];
		array[max_child] = temp;

		print_array(array, size);
		root = max_child;
	}
}

/**
 * heapify - Builds a max heap from the
 * @array: An array to be sorted
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
	ssize_t start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, size, start, size - 1);
		start--;
	}
}
/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;
	int temp;

	if (array ==  NULL || size < 2)
		return;

	heapify(array, size);
	while (end > 0)
	{
		temp = array[0];
		array[0] = array[end];
		array[end] = temp;

		print_array(array, size);

		sift_down(array, size, 0, --end);
	}
}
