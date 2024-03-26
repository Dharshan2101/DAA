#include <stdio.h>
#include <stdlib.h>

// Structure for items
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value per unit weight
int compare(const void *a, const void *b) {
    double ratio1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double ratio2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (ratio2 > ratio1) ? 1 : -1;
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(int W, struct Item arr[], int n) {
    // Sort items based on value per unit weight
    qsort(arr, n, sizeof(arr[0]), compare);

    int currentWeight = 0;
    double finalValue = 0.0;

    // Loop through each item
    for (int i = 0; i < n; i++) {
        // If adding the entire item would not exceed the weight limit
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            // If adding the entire item would exceed the weight limit, take a fraction of it
            int remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int W; // Weight capacity of knapsack
    printf("Enter the weight capacity of the knapsack: ");
    scanf("%d", &W);

    int n; // Number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item arr[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    double maxValue = fractionalKnapsack(W, arr, n);
    printf("The maximum value that can be obtained is: %.2lf\n", maxValue);

    return 0;
}

