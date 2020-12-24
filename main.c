#include <stdio.h>
#include "sort.h"
#define SIZE 50

void printArr(int *arr)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d", arr[i]);
        if (i < SIZE - 1)
        {
            printf(",");
        }
    }
    printf("\n");
}

int main()
{
    int array[50];

    for (size_t i = 0; i < SIZE; i++)
    {
        // geting the array element from the user
        scanf("%d", (array + i));
    }

    insertion_sort(array, SIZE);
    
    printArr(array);

    return 0;
}