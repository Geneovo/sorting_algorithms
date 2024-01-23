#include "sort.h"

/**
  * swap_ints - Swap two integers in an array.
  * @first: The first integer to swap
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
  * shell_sort - Sort an array of integers in ascending order using
  *	the shell sort algorithm.
  * @array: An array of integers.
  * @size: The size of the array.
  *
  * Description: Uses the Knuth.interval sequence.
  */
void shell_sort(int *array, size_t size)
{
	size_t rec, i , k;

	if (array == NULL || size < 2)
		return;
	for (rec = 1; rec < (size / 3);)
		gap = gap * 3 + 1;
	for (; rec>= 1; gap /= 3)
	{
		for (i = rec; i < size; i++)
		{
			j = i;
			while (j >= rec && array[j - rec] > array[j])
			{
				swap_ints(array + j, array + (j - rec));
				j -= rec;
			}
		}
		print_array(array, size);
	}
}
