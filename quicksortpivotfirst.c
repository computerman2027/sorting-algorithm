#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int first, int last)
{
    int pivot = arr[first];
    int up = last;
    int down = first;
    while (down < up)
    {
        while (arr[down] <= pivot && down < up)
        {
            down++;
        }
        while (arr[up] > pivot)
        {
            up--;
        }
        if (down < up)
        {
            swap(&arr[down], &arr[up]);
        }
    }
    swap(&arr[first], &arr[up]);
    return up;
}

void quickSort(int arr[], int first, int last)
{
    if (first >= last)
        return;
    int pi = partition(arr, first, last);
    quickSort(arr, first, pi - 1);
    quickSort(arr, pi + 1, last);
}

int main()
{
    printf("ENTER NUMBER OF ELEMENTS\n");
    int n, i;
    scanf("%d", &n);
    if (n < 1)
    {
        printf("INVALID INPUT\n");
        return 0;
    }
    int *array = (int *)malloc(n * sizeof(int));
    printf("ENTER ELEMENTS OF ARRAY\n");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("DISPLAYING ELEMENTS OF ARRAY\n");
    for (i = 0; i < n; i++)
        printf(i == n - 1 ? "%d\n" : "%d, ", array[i]);
    quickSort(array, 0, n - 1);
    printf("DISPLAYING ELEMENTS OF ARRAY AFTER SORTING\n");
    for (i = 0; i < n; i++)
        printf(i == n - 1 ? "%d\n" : "%d, ", array[i]);
    return 0;
}