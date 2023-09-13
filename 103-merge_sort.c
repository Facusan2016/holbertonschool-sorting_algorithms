#include "sort.h"

void merge(int *array, int *left, int left_size, int *right, int right_size)
{
    int i = 0, j = 0, k = 0, x = 0;

    printf("Merging...\n[left]: ");
    for (x = 0; x < left_size; x++)
    {
        printf("%d", left[x]);
        if (x != left_size - 1)
            printf(", ");
    }

    printf("\n[right]: ");
    for (x = 0; x < right_size; x++)
    {
        printf("%d", right[x]);
        if (x != right_size - 1)
            printf(", ");
    }

    printf("\n");

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }

    while (i < left_size)
        array[k++] = left[i++];

    while (j < right_size)
        array[k++] = right[j++];

    printf("[Done]: ");
    for (x = 0; x < left_size + right_size; x++)
    {
        printf("%d", array[x]);
        if (x != left_size + right_size - 1)
            printf(", ");
    }
    printf("\n");
}

void merge_sort(int *array, size_t size)
{
    int *temp_array = NULL, *left = NULL, *right = NULL;
    int i, mid;

    if (!array || size <= 1)
        return;

    temp_array = (int *)malloc(size * sizeof(int));

    if (!temp_array)
        exit(1);

    mid = size / 2;
    left = temp_array;
    right = temp_array + mid;

    for (i = 0; i < mid; i++)
        left[i] = array[i];
    for (i = mid; i < (int)size; i++)
        right[i - mid] = array[i];

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    
    merge(array, left, mid, right, size - mid);
    free(temp_array);
}
