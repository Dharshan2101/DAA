#include <stdio.h>

void printFibonacci(int n) {
    int n1 = 0, n2 = 1, n3, i;
    printf("%d %d ", n1, n2);

    for (i = 2; i < n; i++) {
        n3 = n1 + n2;
        printf("%d ", n3);
        n1 = n2;
        n2 = n3;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Number of elements should be greater than 0.\n");
        return 1;
    }

    printf("Fibonacci series: ");
    if (n >= 1)
        printf("%d ", 0);
    if (n >= 2)
        printf("%d ", 1);
    printFibonacci(n);
    
    return 0;
}

