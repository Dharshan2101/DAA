#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num, int i) {
    if (i == 1) {
        return true;
    }
    if (num % i == 0) {
        return false;
    }
    return isPrime(num, i - 1);
}

void generatePrimes(int n, int i) {
    if (i > n) {
        return;
    }
    if (isPrime(i, i / 2)) {
        printf("%d ", i);
    }
    generatePrimes(n, i + 1);
}

int main() {
    int limit;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);
    printf("Prime numbers up to %d are:\n", limit);
    generatePrimes(limit, 2);
    return 0;
}

