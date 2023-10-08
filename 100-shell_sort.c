#include "sort.h"

/**
* shell_sort - sorts an array of int in ascending order using the Knuth seq
* @array: array of ints to sort
* @size: size of array
* Return: none
*/
void shell_sort(int *array, size_t size)
{
	int gap = 1, i, hold, j = 0;

	if (size <= 1 || !array)
		return;
	while ((size_t)gap <= size / 3)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap = (gap - 1) / 3)
	{
		for (i = gap; i < (int)size; i++)
		{
			hold = array[i];
			for (j = i - gap; array[j] > hold && j >= 0; j = j - gap)
				array[j + gap] = array[j];
			array[j + gap] = hold;
		}
		for (j = 0; j < (int)size - 1; j++)
			printf("%d, ", array[j]);
		printf("%d\n", array[j]);
	}
}
