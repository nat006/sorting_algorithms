#include "sort.h"

void exchange_integers(int *x, int *y);
int perform_lomuto_partition(int *arr, size_t size, int left, int right);
void apply_lomuto_sort(int *arr, size_t size, int left, int right);
void execute_quick_sort(int *arr, size_t size);

/**
 * exchange_integers - Exchange two integers in an array.
 * @x: The first integer to exchange.
 * @y: The second integer to exchange.
 */
void exchange_integers(int *x, int *y)
{
    int temporary;

    temporary = *x;
    *x = *y;
    *y = temporary;
}

/**
 * perform_lomuto_partition - Arrange a subset of an array of integers based on
 *                            the Lomuto partition scheme (last element as pivot).
 * @arr: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to arrange.
 * @right: The ending index of the subset to arrange.
 *
 * Return: The final partition index.
 */
int perform_lomuto_partition(int *arr, size_t size, int left, int right)
{
    int *pivot, above, below;

    pivot = arr + right;
    for (above = below = left; below < right; below++)
    {
        if (arr[below] < *pivot)
        {
            if (above < below)
            {
                exchange_integers(arr + below, arr + above);
                print_array(arr, size);
            }
            above++;
        }
    }

    if (arr[above] > *pivot)
    {
        exchange_integers(arr + above, pivot);
        print_array(arr, size);
    }

    return (above);
}

/**
 * apply_lomuto_sort - Implement the quicksort algorithm using recursion.
 * @arr: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to arrange.
 * @right: The ending index of the array partition to arrange.
 *
 * Description: Utilizes the Lomuto partition scheme.
 */
void apply_lomuto_sort(int *arr, size_t size, int left, int right)
{
    int partition;

    if (right - left > 0)
    {
        partition = perform_lomuto_partition(arr, size, left, right);
        apply_lomuto_sort(arr, size, left, partition - 1);
        apply_lomuto_sort(arr, size, partition + 1, right);
    }
}

/**
 * execute_quick_sort - Sort an array of integers in ascending order using the
 *                     quicksort algorithm.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Description: Utilizes the Lomuto partition scheme. Prints the array after
 *              each exchange of two elements.
 */
void execute_quick_sort(int *arr, size_t size)
{
    if (arr == NULL || size < 2)
        return;

    apply_lomuto_sort(arr, size, 0, size - 1);
}
