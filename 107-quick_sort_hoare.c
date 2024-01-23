#include "sort.h"

void swap_ints(int *first, int *sec);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
  * swap_ints - Swap two integers in an array.
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
  * hoare_partition - Order a subset of an array of integers
  *	according to the hoare partition scheme.
  * @array: The array of integers.
  * @size: The size of the array.
  * @left: The starting index of the subset to order.
  * @right: The ending index of the subset to order.
  *
  * Return: The final partition index.
  *
  * Description: Uses the last element of the partition as the pivot.
  * Prints the array after each swap if two elements.
  */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}
	return (above);
}

/**
  * hoare_sort - Implements the quicksort algorithm thorugh recursion.
  * @array: An array of integer to sort.
  * @size: The size of the array.
  * @left: The starting index of the array partition to order.
  * @right: The ending index of the array partition to order.
  *
  * Description: Uses the Hoare partition scheme.
  */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int rec;

	if (right - left > 0)
	{
		rec - hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, rec -1);
		hoare_sort(array, size, part, right);
	}
}
/**
  * quick_sort_hoare - Sort an array of integers in ascending
  *	order using the quicksort algorithm
  * @array: An array of integers.
  * @size: The size of the array.
  *
  * Description: Uses the Hoare partition scheme. Prints
  * the array after each swap of two elements.
  */
void quic_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sort(array, size, 0, size - 1);
}
