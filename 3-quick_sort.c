#include "sort.h"

/**
 * swap - Function to swap two elements of an array.
 * @array: Array.
 * @i: i index.
 * @j: j index.
 * Return: Nothing
*/

void swap(int *array, size_t i, size_t j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}

/**
 * pivot - Function that sorts and return the sorted index.
 * @array: Array.
 * @low: Low section of the array to be sorted.
 * @high: High section of the array to be sorted.
 * @arr_size: Size of the array.
 * Return: The index where the array is sorted.
*/

int pivot(int *array, int low, int high, int arr_size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j);
			print_array(array, arr_size);
		}
	}

	swap(array, i + 1, high);
	print_array(array, arr_size);
	return (i + 1);
}

/**
 * r_quick_sort - Recursive quick sort.
 * @array: Array.
 * @low: Low section of the array to be sorted.
 * @high: High section of the array to be sorted.
 * @arr_size: Size of the array
 * Return: Nothing
*/

void r_quick_sort(int *array, int low, int high, int arr_size)
{
	int pi;

	if (low < high)
	{
		pi = pivot(array, low, high, arr_size);
		r_quick_sort(array, low, pi - 1, arr_size);
		r_quick_sort(array, pi + 1, high, arr_size);
	}
}

/**
 * quick_sort - Sorts an array using quick_sort.
 * @array: Array.
 * @size: Size of the array.
 * Return: Nothing
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	r_quick_sort(array, 0, size - 1, size);
}
