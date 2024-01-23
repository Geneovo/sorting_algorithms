#include "sort.h"

void swap_ints(int *first, int *sec);
void max_heapify(int *aray, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
  * max_heapify - Turn a binary tree into a complete binary heap
  * @array: An array of integers representinga binary tree.
  * @size: The size of the array/tree.
  * @base: The index of the base of the row of the tree.
  * @root: The root node of the binary tree.
  */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, huge;

	left = 2 * root + 1;
	right = 2 * root + 2;
	huge = root;

	if (left < base && array[left] > array[huge])
		huge = left;
	if (right < base && array[right] > array[huge])
		huge = right;
	if (huge != root)
	{
		swap_ints(array + root, array + huge);
		print_array(array, size);
		max_heapify(array, size, base, huge);
	}
}

/**
  * heap_sort - Sort an array of integers in ascending order
  *	using the heap sort algorithm.]
  * @array: An array of integers.
  * @size: The size of the array.
  *
  * Description: Implements the shift-down heap sort
  * algorithm. Prints the array after each swap.
  */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = (size / 2) - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
