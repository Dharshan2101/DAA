#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair result, left, right;
    int mid;

    // If there is only one element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.min = arr[high];
            result.max = arr[low];
        } else {
            result.min = arr[low];
            result.max = arr[high];
        }
        return result;
    }

    // If there are more than two elements, divide the array into two halves
    mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Compare minimums and maximums of two halves
    if (left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    if (left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Pair minmax = findMinMax(arr, 0, n - 1);

    printf("Minimum element in the array: %d\n", minmax.min);
    printf("Maximum element in the array: %d\n", minmax.max);

    return 0;
}

