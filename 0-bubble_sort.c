#include "sort.h"

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
		for (j = 0; j < size -1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				i = 0;
			}
		}
		temp++;
	}
}
