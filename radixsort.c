#include <stdio.h>
#include <stdlib.h>

// Function to perform counting sort based on a specific digit position
void countSort(int *v, int n, int pos) {
    int freq[10] = {0};
    int *ans = (int *)malloc(n * sizeof(int));

    // Calculate frequency of each digit at the current position
    for (int i = 0; i < n; i++) {
        freq[(v[i] / pos) % 10]++;
    }

    // Cumulative frequency
    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i - 1];
    }

    // Build the sorted array based on the current position
    for (int i = n - 1; i >= 0; i--) {
        ans[--freq[(v[i] / pos) % 10]] = v[i];
    }

    // Copy sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        v[i] = ans[i];
    }

    free(ans);
}

// Function to perform radix sort
void radixSort(int *v, int n) {
    int max_ele = v[0];

    // Find the maximum element in the array
    for (int i = 1; i < n; i++) {
        if (v[i] > max_ele) {
            max_ele = v[i];
        }
    }

    // Perform counting sort for each digit position
    for (int pos = 1; max_ele / pos > 0; pos *= 10) {
        countSort(v, n, pos);
    }
}

// Main function
int main() {
    int n;

    printf("ENTER NUMBER OF ELEMENTS\n");
    scanf("%d", &n);

    if (n < 1) {
        printf("INVALID\n");
        return 0;
    }

    int *a = (int *)malloc(n * sizeof(int));

    printf("ENTER ELEMENTS\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("UNSORTED ARRAY\n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n");

    radixSort(a, n);

    printf("SORTED ARRAY\n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}
