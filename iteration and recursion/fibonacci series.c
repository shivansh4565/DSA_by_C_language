#include <stdio.h>

// Recursive function to find the nth Fibonacci number
int fibonacci(int n) {
    // Base case: first two Fibonacci numbers are 0 and 1
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        // Recursive call for the (n-1)th and (n-2)th Fibonacci numbers
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    // Ask user for the number of terms
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci Series up to %d terms:\n", n);

    // Print the Fibonacci series up to n terms
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
