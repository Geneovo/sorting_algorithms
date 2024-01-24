#include "sort.h"

/**
 * swap_down - A function that swaps down nodes in the heap
 *
 * @array: The heap array to be sorted
 * @root: The root of the heap
 * @high: The starting index to be sorted
 * @size: The size of the array
 * Return: Nothing
 */
void swap_down(int *array, size_t root, size_t high, size_t size)
{
	size_t low = 0, middle = 0, tmp = 0;
	int aux;

	while ((low = (2 * root + 1)) <= high)
	{
		tmp = root;
		middle = low + 1;
		if (array[tmp] < array[low])
			tmp = low;
		if (middle <= high && array[tmp] < array[middle])
			tmp = middle;
		if (tmp == root)
			return;
		aux = array[root];
		array[root] = array[tmp];
		array[tmp] = aux;
		print_array(array, size);
		root = tmp;
	}
}

/**
 * heap_sort - A function that sorts an array of integers in ascending
 * order using the Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t high = 0, space = 0;
	int tmp = 0;

	if (array == NULL || size < 2)
		return;

	for (space = (size - 2) / 2; 1; space--)
	{
		swap_down(array, space, size - 1, size);
		if (space == 0)
			break;
	}

	high = size - 1;
	while (high > 0)
	{
		tmp = array[high];
		array[high] = array[0];
		array[0] = tmp;
		print_array(array, size);
		high--;
		swap_down(array, 0, high, size);
	}
}
