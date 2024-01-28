#include "sort.h"
#include <stdlib.h>

/**
 * getMax - Function that help to find the maximum element in an array
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: The maximum element
 */
int getMax(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * countingSort - Function that perform counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The current exponent
 * @buff: Buffer
 */
void countingSort(int *array, size_t size, int exp, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - This sorts an array of integers using LSD Radix sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp, buff);
		print_array(array, size);
	}
}
