#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers in ascending
 * order using the selection sort algorithm
 *
 * @array: An array to sort
 * @size: The size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int aux;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			aux = array[i];
			array[i] = array[min];
			array[min] = aux;
			print_array(array, size);
		}
	}
}
