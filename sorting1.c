#include <stdio.h>
#define MAXITEM 20

void insertionsort(int *arr, int n)
{
    int temp, i, j;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0 && temp < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

void selectionsort(int *arr, int n)
{
    int i, j, temp, pos, flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        temp = arr[i];
        pos = i;
        flag = 0;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < temp)
            {
                temp = arr[j];
                pos = j;
                flag = 1;
            }
        }
        if (flag == 0)
            continue;
        arr[pos] = arr[i];
        arr[i] = temp;
    }
}

void bubblesort(int *arr, int n)
{
    int i, j, temp, flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            return;
    }
}
void display(int *arr, int n, int type)
{
    int i;
    if (type == 0)
        printf("ARRAY AFTER SORTING = ");
    else
        printf("ARRAY BEFORE SORTING = ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int insertItem(int *arr, int n)
{
    int item;
    printf("Enter a number to insert : ");
    scanf("%d", &item);
    if (n == MAXITEM)
    {
        printf("Element cannot be inserted\n");
        return n;
    }
    arr[n] = item;
    return n + 1;
}
int main()
{
    int n, i, choice, c = 0;
    int arr[MAXITEM];
    printf("Enter size of array : ");
    scanf("%d", &n);
    if (n < 1 || n > MAXITEM)
    {
        printf("INVALID SIZE\n");
        return 0;
    }
    printf("Enter %d numbers : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("ARRAY before sorting= ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    while (1)
    {
        printf("MENU\n1. BUBBLE SORT\n2. SELECTION SORT\n3. INSERTION SORT\n4. EXIT\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (c != 0)
            {
                n = insertItem(arr, n);
                display(arr, n, 1);
            }
            bubblesort(arr, n);
            display(arr, n, 0);
            c++;
            break;
        case 2:
            if (c != 0)
            {
                n = insertItem(arr, n);
                display(arr, n, 1);
            }
            selectionsort(arr, n);
            display(arr, n, 0);
            c++;
            break;
        case 3:
            if (c != 0)
            {
                n = insertItem(arr, n);
                display(arr, n, 1);
            }
            insertionsort(arr, n);
            display(arr, n, 0);
            c++;
            break;
        case 4:
            printf("END OF PROGRAM\n");
            return 0;
        default:
            printf("INVALID INPUT\n");
        }
    }
    return 0;
}