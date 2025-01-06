#include <stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapsort(int arr[], int n)
{
    buildHeap(arr,n);
    int i;
    for(i=n-1;i>=0;i--)
    {
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("ENTER NUMBER OF ELEMENTS\n");
    int n, i;
    scanf("%d", &n);
    if (n < 1 )
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
    heapsort(array, n);
    printf("DISPLAYING ELEMENTS OF ARRAY AFTER SORTING\n");
    for (i = 0; i < n; i++)
        printf(i == n - 1 ? "%d\n" : "%d, ", array[i]);
    return 0;
}
