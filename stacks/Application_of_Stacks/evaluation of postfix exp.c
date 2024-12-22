/*
Postfix expressions (Reverse Polish Notation) are mathematical expressions in which the operator follows the operands. Postfix notation is popular because it doesn't require parentheses to enforce operator precedence, and it can be evaluated efficiently using a stack.

In a postfix expression, operands are pushed onto the stack, and when an operator is encountered, the necessary operands are popped from the stack, the operation is performed, and the result is pushed back onto the stack.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack to hold operands
int stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(int value) {
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        // If the character is a digit (operand)
        if (isdigit(exp[i])) {
            push(exp[i] - '0'); // Convert character to integer and push to stack
        }
        // If the character is an operator
        else {
            int operand2 = pop();  // Pop the second operand
            int operand1 = pop();  // Pop the first operand

            switch (exp[i]) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
                default: printf("Invalid operator: %c\n", exp[i]); return -1;
            }
        }
    }
    return pop(); // The final result will be the only element in the stack
}

int main() {
    char exp[] = "43+2*";  // Example postfix expression
    printf("Result: %d\n", evaluatePostfix(exp)); // Output should be 16
    return 0;
}
/*
conclsuion


*/