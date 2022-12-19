#include "sort.h"

/**
 * swap2 - swaps two numbers
 * @a : integer 1
 * @b : integer b
 */

void swap2(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array : array of ints to sort
 * @size : size of array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0, j, temp = size;

	if (!array || size < 2)
		return;

	while (i != 1)
	{
		i = 1;
		for (j = 0; j < temp - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap2(array + j, array + j + 1);
				print_array(array, size);
				i = 0;
			}
		}
		temp--;
	}
}
