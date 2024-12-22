/*
Two Variables Polynomial
For two-variable polynomials, we use a 2D array where each element represents a coefficient for a specific pair of powers (x^i * y^j).

Polynomial Representation (Two Variables):

P(x, y) = a00 + a01*x + a10*y + a11*x*y + ...
Code for Two Variables Polynomial Operations
*/
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for a 2-variable polynomial
typedef struct PolyNode2D {
    int coef;           // Coefficient
    int exp_x;          // Exponent of x
    int exp_y;          // Exponent of y
    struct PolyNode2D *next; // Pointer to the next term
} PolyNode2D;

// Function to create a new node
PolyNode2D* createNode2D(int coef, int exp_x, int exp_y) {
    PolyNode2D *newNode = (PolyNode2D*)malloc(sizeof(PolyNode2D));
    newNode->coef = coef;
    newNode->exp_x = exp_x;
    newNode->exp_y = exp_y;
    newNode->next = NULL;
    return newNode;
}

// Function to add two 2-variable polynomials
PolyNode2D* addPoly2D(PolyNode2D *p1, PolyNode2D *p2) {
    PolyNode2D *result = NULL, *temp, *prev = NULL;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp_x > p2->exp_x || (p1->exp_x == p2->exp_x && p1->exp_y > p2->exp_y)) {
            temp = createNode2D(p1->coef, p1->exp_x, p1->exp_y);
            p1 = p1->next;
        } else if (p1->exp_x < p2->exp_x || (p1->exp_x == p2->exp_x && p1->exp_y < p2->exp_y)) {
            temp = createNode2D(p2->coef, p2->exp_x, p2->exp_y);
            p2 = p2->next;
        } else {  // exponents are the same
            temp = createNode2D(p1->coef + p2->coef, p1->exp_x, p1->exp_y);
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
        temp = createNode2D(p1->coef, p1->exp_x, p1->exp_y);
        prev->next = temp;
        prev = temp;
        p1 = p1->next;
    }
    while (p2 != NULL) {
        temp = createNode2D(p2->coef, p2->exp_x, p2->exp_y);
        prev->next = temp;
        prev = temp;
        p2 = p2->next;
    }

    return result;
}

// Function to print a 2-variable polynomial
void printPoly2D(PolyNode2D *p) {
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
        printf("%dx^%dy^%d", p->coef, p->exp_x, p->exp_y);
        
        p = p->next;
    }
    printf("\n");
}

int main() {
    // Polynomial 1: 2x^2y + 3xy^2
    PolyNode2D *p1 = createNode2D(2, 2, 1);
    p1->next = createNode2D(3, 1, 2);

    // Polynomial 2: x^3 + 4xy^2
    PolyNode2D *p2 = createNode2D(1, 3, 0);
    p2->next = createNode2D(4, 1, 2);

    printf("Polynomial 1: ");
    printPoly2D(p1);
    printf("Polynomial 2: ");
    printPoly2D(p2);

    PolyNode2D *sum = addPoly2D(p1, p2);
    printf("Sum: ");
    printPoly2D(sum);

    return 0;
}


/*


output 
Polynomial 1: 2x^2y + 3x^1y^2
Polynomial 2: x^3 + 4x^1y^2
Sum: 2x^2y + 3x^1y^2 + x^3

*/