#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - A function that sorts an array of integers in ascending
 * order using the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int i, maximum;
	int *count = NULL, *cp = NULL;
	size_t j, tmp, final = 0;

	if (array == NULL || size < 2)
		return;
	cp = malloc(sizeof(int) * size);
	if (cp == NULL)
		return;
	for (j = 0, maximum = 0; j < size; j++)
	{
		cp[j] = array[j];
		if (array[j] > maximum)
			maximum = array[j];
	}
	count = malloc(sizeof(int) * (maximum + 1));
	if (count == NULL)
	{
		free(cp);
		return;
	}
	for (i = 0; i <= maximum; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[array[j]] += 1;
	for (i = 0; i <= maximum; i++)
	{
		tmp = count[i];
		count[i] = final;
		final += tmp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[cp[j]]] = cp[j];
		count[cp[j]] += 1;
	}
	print_array(count, maximum + 1);
	free(count);
	free(cp);
}
