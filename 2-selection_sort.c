#include "sort.h"
/**
 * selection_sort - Sorts an array using the selection sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 * Return: Nothing.
*/

void selection_sort(int *array, size_t size)
{
	size_t min, i, j, aux;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;

		if (min != i)
		{
			aux = array[i];
			array[i] = array[min];
			array[min] = aux;
			print_array(array, size);
		}

	}
}
