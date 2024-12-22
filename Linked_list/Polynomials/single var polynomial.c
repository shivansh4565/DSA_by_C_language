/*

Here's a short C code demonstrating the representation, addition, subtraction, and multiplication of single-variable and two-variable polynomials.

Single Variable Polynomial
In single-variable polynomials, we represent the polynomial as an array where each element corresponds to the coefficient of a term, and the index represents the power of the variable.


Polynomial Representation (Single Variable):

P(x) = a0 + a1*x + a2*x^2 + ... + an*x^n
Code for Single Variable Polynomial Operations




*/
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
typedef struct PolyNode {
    int coef;           // Coefficient
    int exp;            // Exponent
    struct PolyNode *next; // Pointer to the next term
} PolyNode;

// Function to create a new node
PolyNode* createNode(int coef, int exp) {
    PolyNode *newNode = (PolyNode*)malloc(sizeof(PolyNode));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to add two polynomials
PolyNode* addPolynomials(PolyNode *p1, PolyNode *p2) {
    PolyNode *result = NULL, *temp, *prev = NULL;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            temp = createNode(p1->coef, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            temp = createNode(p2->coef, p2->exp);
            p2 = p2->next;
        } else {  // p1->exp == p2->exp
            temp = createNode(p1->coef + p2->coef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }

    // Add remaining terms
    while (p1 != NULL) {
        temp = createNode(p1->coef, p1->exp);
        prev->next = temp;
        prev = temp;
        p1 = p1->next;
    }
    while (p2 != NULL) {
        temp = createNode(p2->coef, p2->exp);
        prev->next = temp;
        prev = temp;
        p2 = p2->next;
    }

    return result;
}

// Function to subtract two polynomials
PolyNode* subtractPolynomials(PolyNode *p1, PolyNode *p2) {
    PolyNode *result = NULL, *temp, *prev = NULL;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            temp = createNode(p1->coef, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            temp = createNode(-p2->coef, p2->exp);  // Subtract by adding negative
            p2 = p2->next;
        } else {
            temp = createNode(p1->coef - p2->coef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }

    // Add remaining terms
    while (p1 != NULL) {
        temp = createNode(p1->coef, p1->exp);
        prev->next = temp;
        prev = temp;
        p1 = p1->next;
    }
    while (p2 != NULL) {
        temp = createNode(-p2->coef, p2->exp);
        prev->next = temp;
        prev = temp;
        p2 = p2->next;
    }

    return result;
}

// Function to multiply two polynomials
PolyNode* multiplyPolynomials(PolyNode *p1, PolyNode *p2) {
    PolyNode *result = NULL, *temp, *prev = NULL;
    
    for (PolyNode *i = p1; i != NULL; i = i->next) {
        for (PolyNode *j = p2; j != NULL; j = j->next) {
            temp = createNode(i->coef * j->coef, i->exp + j->exp);
            
            // Insert temp into result
            PolyNode *prevResult = NULL, *currResult = result;
            while (currResult != NULL && currResult->exp > temp->exp) {
                prevResult = currResult;
                currResult = currResult->next;
            }
            if (currResult != NULL && currResult->exp == temp->exp) {
                currResult->coef += temp->coef;  // Combine coefficients if exponents match
                free(temp);
            } else {
                if (prevResult == NULL) {
                    temp->next = result;
                    result = temp;
                } else {
                    prevResult->next = temp;
                    temp->next = currResult;
                }
            }
        }
    }

    return result;
}

// Function to print the polynomial
void printPolynomial(PolyNode *p) {
    if (p == NULL) {
        printf("0\n");
        return;
    }
    int firstTerm = 1;  // Flag to handle the "+" sign before the first term
    while (p != NULL) {
        if (firstTerm) {
            firstTerm = 0;
        } else {
            printf(" + ");
        }
        
        // Print coefficient and exponents
        printf("%dx^%d", p->coef, p->exp);
        
        p = p->next;
    }
    printf("\n");
}

int main() {
    // Polynomial 1: 3x^2 + 2x + 1
    PolyNode *p1 = createNode(3, 2);
    p1->next = createNode(2, 1);
    p1->next->next = createNode(1, 0);

    // Polynomial 2: 2x^2 + 1
    PolyNode *p2 = createNode(2, 2);
    p2->next = createNode(1, 0);

    printf("Polynomial 1: ");
    printPolynomial(p1);
    printf("Polynomial 2: ");
    printPolynomial(p2);

    PolyNode *sum = addPolynomials(p1, p2);
    printf("Sum: ");
    printPolynomial(sum);

    PolyNode *difference = subtractPolynomials(p1, p2);
    printf("Difference: ");
    printPolynomial(difference);

    PolyNode *product = multiplyPolynomials(p1, p2);
    printf("Product: ");
    printPolynomial(product);

    return 0;
}
/*
Polynomial 1: 3x^2 + 2x^1 + 1x^0
Polynomial 2: 2x^2 + 1x^0
Sum: 5x^2 + 2x^1 + 2x^0
Difference: x^2 + 2x^1
Product: 6x^4 + 7x^3 + 5x^2 + 2x^1


*/