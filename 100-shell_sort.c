#include "sort.h"

/**
 * _swap - This function swaps two numbers
 *
 * @a: integer
 * @b: integer
 */

void _swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * backward_insertion - This function swaps two nodes right left position
 *
 * @array: The array
 * @gap: Gap
 * @act: This is the Actual Position in the array
 */
void backward_insertion(int *array, int gap, int act)
{
	int i;

	for (i = act - gap; i >= 0; i -= gap, act -= gap)
	{
		if (array[i] > array[act])
			_swap(&array[i], &array[act]);
		else
			break;
	}
}

/**
 * shell_sort - This function sort an array using the Shell sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, i, j;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = 0, j = gap; j < size; i++, j++)
		{
			if (array[i] > array[j])
			{
				_swap(&array[i], &array[j]);
				backward_insertion(array, gap, i);
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
