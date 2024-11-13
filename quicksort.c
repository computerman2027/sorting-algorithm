#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void random(int arr[], int low, int high)
{
    int random = low + rand() % (high - low);
    int temp = arr[random];
    arr[random] = arr[high];
    arr[high] = temp;
}
int partition(int arr[], int first, int last)
{
    random(arr,first,last);
    int pivot = arr[last];
    int i = first - 1;
    int j = first;
    for (; j < last; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[last]);
    return i + 1;
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
    int n;
    scanf("%d", &n);
    if (n < 1)
    {
        printf("INVALID INPUT\n");
        return 0;
    }
    int array[n];
    printf("ENTER ELEMENTS OF ARRAY\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("DISPLAYING ELEMENTS OF ARRAY");
    for (int i = 0; i < n; i++)
        printf("%d, ", array[i]);
    printf("\n");
    quickSort(array, 0, n - 1);
    printf("DISPLAYING ELEMENTS OF ARRAY AFTER SORTING\n");
    for (int i = 0; i < n; i++)
        printf("%d, ", array[i]);
    printf("\n");
    return 0;
}
