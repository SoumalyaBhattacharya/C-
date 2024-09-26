#include <stdio.h>

// Function to compute the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int numTerms;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &numTerms);

    printf("Fibonacci series up to %d terms:\n", numTerms);
    for (int i = 0; i < numTerms; ++i) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}

