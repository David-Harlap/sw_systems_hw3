#include "sort.h"
#include <stdio.h>

void shift_element(int* arr, int i)
{
    while (i--)
    {
        // shifting i elements to the right
        *(arr + i + 1) = *(arr + i);
    }
}

void insertion_sort(int *arr, int len)
{
    int j, shift;
    for (size_t i = 1; i < len; i++)
    {
        shift = 0;
        j = i - 1;
        while (j >= 0 && *(arr + j) > *(arr + i))
        {
            // conting the amound of elements that need to shift right
            shift++;
            j--;
        }
        j++;
        if (shift > 0 && shift + j < len)
        {
            // if need to be shift, save the first that dont need to shift and then shift
            int temp = *(arr + i);
            shift_element(arr + j, shift);
            *(arr + j) = temp;
        }
    }
}