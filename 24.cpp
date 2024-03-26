#include <stdio.h>

void printMinMaxSequence(int arr[], int n) {
    if (n == 0) {
        printf("No elements in the list.\n");
        return;
    }

    printf("Minimum and maximum value sequence for each subsequence:\n");
    for (int i = 0; i < n; i++) {
        int min = arr[i], max = arr[i];
        for (int j = i; j < n; j++) {
            if (arr[j] < min)
                min = arr[j];
            if (arr[j] > max)
                max = arr[j];
            printf("Subsequence [%d, %d]: Min = %d, Max = %d\n", i, j, min, max);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printMinMaxSequence(arr, n);
    return 0;
}

