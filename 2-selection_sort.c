#include "sort.h"

/**
  * swap_ints - Swap the integers in an array
  * @first: The first integer to swap.
  * @sec: The second integer to swap.
  */
void swap_ints(int *first, int *sec)
{
	int tmp;

	tmp = *first;
	*first = *sec;
	*sec = tmp;
}

/**
  * seclection_sort - Sort an array of integers in an ascending order
  *		using the selection sort algorithm.
  * @size: The size of the array
  * @array: The array of integers
  *
  * Description: Printd the array after each swap
  */
void selection_sort(int *array, size_t size)
{
	int *less;
	size_t i, k;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		less = array + i;
		for (k = i + 1; k < size; k++)
			less = (array[k] < *less) ? (array + k) : less;
		if ((array + i) != less)
		{
			swap_ints(array + i, less);
			print_array(array, size);
		}
	}
}
