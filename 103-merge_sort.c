#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge_partition(size_t low, size_t high, int *array, int *top);

/**
 * merge_sort - A function that sorts an array of integers in ascending
 * order using the Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t x = 0;
	int *top = NULL;

	if (array == NULL || size < 2)
		return;
	top = malloc(sizeof(int) * size);
	if (top == NULL)
		return;
	for (; x < size; x++)
		top[x] = array[x];
	merge_partition(0, size, array, top);
	free(top);
}

/**
 * merge - A function that merges two sorted arrays
 *
 * @array: The array to be sorted
 * @low: The starting index of the array
 * @middle: The middle index of the array
 * @high: The ending index of the array
 * @dest: Destination for the data
 * @src: Input data
 * Return: Nothing
 */
void merge(size_t low, size_t middle, size_t high, int *dest, int *src)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + low, middle - low);
	printf("[right]: ");
	print_array(src + middle, high - middle);
	i = low;
	j = middle;
	k = low;

		for (; k < high; k++)
		{
			if (i < middle && (j >= high || src[i] <= src[j]))
			{
				dest[k] = src[i];
				i++;
			}
			else
			{
				dest[k] = src[j];
				j++;
			}
		}
		printf("Done]: ");
		print_array(dest + low, high - low);
}

/**
 * merge_partition - A function that splits the array recursively
 *
 * @low: The starting index of the array
 * @high: The ending index of the array
 * @array: The array to be sorted
 * @top: The copy of the array
 * Return: Nothing
 */
void merge_partition(size_t low, size_t high, int *array, int *top)
{
	size_t middle = 0;

	if (high - low < 2)
		return;
	middle = (low + high) / 2;
	merge_partition(low, middle, array, top);
	merge_partition(middle, high, array, top);
	merge(low, middle, high, array, top);
	for (middle = low; middle < high; middle++)
		top[middle] = array[middle];
}
