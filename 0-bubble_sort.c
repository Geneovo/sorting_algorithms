#include "sort.h"

/**
 * bubble_sort - A function for bubble sort algorithm
 *
 * @array: The array to sort
 * @size: The size of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int swapped = 0;

	if (array == NULL || size == 0)
		return;
	for (; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapped = array[j + 1];
				array[j + 1] = array[j];
				array[j] = swapped;
				print_array(array, size);
			}
		}
	}
}
