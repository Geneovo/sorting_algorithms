#include "sort.h"

/**
 * _swap - This function swaps two numbers
 *
 * @a: first integer
 * @b: second integer
 */
void _swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * backward_insertion - This function will swap two nodes from the right
 * to the left position
 *
 * @array: The aray to be sorted
 * @space: space
 * @idx: The actual position in the array
 */
void backward_insertion(int *array, int space, int idx)
{
	int i;

	for (i = idx - space; i >= 0; i -= space, idx -= space)
	{
		if (array[i] > array[idx])
			_swap(&array[i], &array[idx]);
		else
			break;
	}
}

/**
 * shell_sort - This function sort an array using shell sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	unsigned int space = 1, i, j;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (space < size / 3)
		space = space * 3 + 1;

	while (space > 0)
	{
		for (i = 0, j = space; j < size; i++, j++)
		{
			if (array[i] > array[j])
			{
				_swap(&array[i], &array[j]);
				backward_insertion(array, space, i);
			}
		}
		print_array(array, size);
		space /= 3;
	}
}
