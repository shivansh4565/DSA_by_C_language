#include <stdio.h>

// Iterative function to calculate factorial
int factorial_iterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;  // Multiply result by i at each step
    }
    return result;
}

int main() {
    int num;

    // Input from user
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    // Call the iterative function
    int result = factorial_iterative(num);
    printf("Factorial of %d (iterative) is: %d\n", num, result);

    return 0;
}
