/*
In the context of Data Structures and Algorithms (DSA), prefix and postfix expressions are critical concepts that are primarily used when evaluating arithmetic expressions or implementing expression evaluation algorithms. Understanding these concepts is especially important when working with stacks, expression trees, or algorithms that involve parsing expressions in different notations.

Prefix and Postfix Expressions in DSA
In DSA, the goal is to evaluate mathematical expressions or convert one notation to another. The three main notations for mathematical expressions are:

Infix: The standard form where the operator is placed between operands (e.g., a + b).
Prefix (Polish Notation): The operator comes before its operands (e.g., + a b).
Postfix (Reverse Polish Notation): The operator comes after its operands (e.g., a b +).
Why Prefix and Postfix?
No need for parentheses: In prefix and postfix notations, parentheses are not required to enforce operator precedence, unlike infix notation. The order of operations is strictly determined by the position of the operators and operands.

Efficient computation: Prefix and postfix expressions can be evaluated easily using stacks, which is why they are commonly used in algorithm design and data structures.

Conversion between Notations
Converting between infix, prefix, and postfix expressions is a common task in DSA. Here's a brief explanation of how these conversions work and how you can evaluate them.

Infix to Postfix Conversion (Using Stack)
In infix notation, operators are placed between operands. However, in postfix notation, the operator follows the operands. This conversion requires a stack to handle operator precedence and parentheses.

Steps for Infix to Postfix Conversion:

Initialize an empty stack for operators and an empty list for the output.
Traverse the infix expression from left to right.
If the current character is an operand, add it to the output.
If the current character is an operator:
While the stack is not empty and the operator at the top of the stack has higher or equal precedence, pop operators from the stack and add them to the output.
Push the current operator onto the stack.
If the current character is a left parenthesis (, push it onto the stack.
If the current character is a right parenthesis ), pop operators from the stack to the output until a left parenthesis is encountered.
After reading the entire expression, pop any remaining operators from the stack and add them to the output.
Example: Infix: a + b * (c - d)

Process a: Add to output → a.
Process +: Push onto stack.
Process b: Add to output → a b.
Process *: Push onto stack (higher precedence than +).
Process (: Push onto stack.
Process c: Add to output → a b c.
Process -: Push onto stack.
Process d: Add to output → a b c d.
Process ): Pop - and add to output → a b c d -. Then pop * and add to output → a b c d - *. Finally pop + and add to output → a b c d - * +.
Postfix expression: a b c d - * +

Infix to Prefix Conversion (Using Stack)
The conversion from infix to prefix is similar, but you need to reverse the expression first, convert it to postfix, and then reverse the result.

Steps for Infix to Prefix Conversion:

Reverse the given infix expression.
Follow the steps for infix to postfix conversion.
After getting the postfix expression, reverse it again to get the prefix expression.
Postfix and Prefix Expression Evaluation (Using Stack)
Evaluating postfix and prefix expressions is straightforward using a stack.

Postfix Evaluation (Using Stack):

Initialize an empty stack.
Traverse the postfix expression from left to right.
If the current character is an operand, push it onto the stack.
If the current character is an operator, pop the top two operands from the stack, apply the operator, and push the result back onto the stack.
After processing the entire expression, the top of the stack will contain the result.
Example (Postfix Evaluation): Postfix: a b + c *

Push a, then b → Stack: a, b
Encounter +: Pop b and a, calculate a + b, and push the result → Stack: a + b
Push c → Stack: a + b, c
Encounter *: Pop c and a + b, calculate (a + b) * c, and push the result → Stack: Result.
Prefix Evaluation (Using Stack):

Initialize an empty stack.
Traverse the prefix expression from right to left.
If the current character is an operand, push it onto the stack.
If the current character is an operator, pop the top two operands from the stack, apply the operator, and push the result back onto the stack.
After processing the entire expression, the top of the stack will contain the result.
Example (Prefix Evaluation): Prefix: * + a b c

Push a, then b → Stack: a, b
Encounter +: Pop b and a, calculate a + b, and push the result → Stack: a + b
Push c → Stack: a + b, c
Encounter *: Pop c and a + b, calculate (a + b) * c, and push the result → Stack: Result.
Applications in DSA
Expression Evaluation: Prefix and postfix notations are commonly used in parsing and evaluating mathematical expressions, especially when parentheses and operator precedence need to be handled.
Compilers: The conversion of infix expressions to prefix or postfix is often used in compilers for intermediate representation.
Stacks and Queues: Both postfix and prefix expressions are evaluated efficiently using stacks. In fact, many algorithms in DSA (like evaluating postfix expressions or converting infix to postfix) rely on stacks as a core data structure.
   
   
                  Example Code for Postfix Evaluation (C)

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
int stack[MAX];
int top = -1;

// Function to push element onto stack
void push(int value) {
    stack[++top] = value;
}

// Function to pop element from stack
int pop() {
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            // If the character is a digit, push its integer value onto the stack
            push(exp[i] - '0');
        } else {
            // If the character is an operator, pop two operands and apply the operator
            int operand2 = pop();
            int operand1 = pop();
            switch (exp[i]) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
            }
        }
    }
    // The result will be the only element left in the stack
    return pop();
}

int main() {
    char exp[] = "23*5+";
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}
