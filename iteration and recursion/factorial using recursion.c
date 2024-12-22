#include <stdio.h>

// Recursive function to calculate factorial
int factorial_recursive(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n <= 1) {
        return 1;
    } else {
        // Recursive call
        return n * factorial_recursive(n - 1);
    }
}

int main() {
    int num;

    // Input from user
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    // Call the recursive function
    int result = factorial_recursive(num);
    printf("Factorial of %d (recursive) is: %d\n", num, result);

    return 0;
}
