/*
To implement operations on 1D, 2D, and 3D arrays in C,
 we can perform various tasks like addition, subtraction, and multiplication on arrays of different dimensions. 
 Below is the extended version of the program that includes operations like addition, subtraction, and multiplication on the 1D, 2D, and 3D arrays.

*/
#include <stdio.h>

int main() {
    // 1D Array Operations
    int oneD1[5] = {1, 2, 3, 4, 5};
    int oneD2[5] = {5, 4, 3, 2, 1};
    int oneDResult[5];

    printf("1D Array Operations:\n");
    // Addition of 1D arrays
    for (int i = 0; i < 5; i++) {
        oneDResult[i] = oneD1[i] + oneD2[i];
    }
    printf("Addition: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", oneDResult[i]);
    }
    printf("\n");

    // Subtraction of 1D arrays
    for (int i = 0; i < 5; i++) {
        oneDResult[i] = oneD1[i] - oneD2[i];
    }
    printf("Subtraction: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", oneDResult[i]);
    }
    printf("\n");

    // Multiplication of 1D arrays
    for (int i = 0; i < 5; i++) {
        oneDResult[i] = oneD1[i] * oneD2[i];
    }
    printf("Multiplication: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", oneDResult[i]);
    }
    printf("\n");

    // 2D Array Operations
    int twoD1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int twoD2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int twoDResult[3][3];

    printf("\n2D Array Operations:\n");
    // Addition of 2D arrays
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            twoDResult[i][j] = twoD1[i][j] + twoD2[i][j];
        }
    }
    printf("Addition:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", twoDResult[i][j]);
        }
        printf("\n");
    }

    // Subtraction of 2D arrays
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            twoDResult[i][j] = twoD1[i][j] - twoD2[i][j];
        }
    }
    printf("Subtraction:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", twoDResult[i][j]);
        }
        printf("\n");
    }

    // Multiplication of 2D arrays
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            twoDResult[i][j] = twoD1[i][j] * twoD2[i][j];
        }
    }
    printf("Multiplication:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", twoDResult[i][j]);
        }
        printf("\n");
    }

    // 3D Array Operations
    int threeD1[2][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}
    };
    int threeD2[2][2][2] = {
        {{8, 7}, {6, 5}},
        {{4, 3}, {2, 1}}
    };
    int threeDResult[2][2][2];

    printf("\n3D Array Operations:\n");
    // Addition of 3D arrays
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                threeDResult[i][j][k] = threeD1[i][j][k] + threeD2[i][j][k];
            }
        }
    }
    printf("Addition:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("%d ", threeDResult[i][j][k]);
            }
        }
        printf("\n");
    }

    // Subtraction of 3D arrays
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                threeDResult[i][j][k] = threeD1[i][j][k] - threeD2[i][j][k];
            }
        }
    }
    printf("Subtraction:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("%d ", threeDResult[i][j][k]);
            }
        }
        printf("\n");
    }

    // Multiplication of 3D arrays
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                threeDResult[i][j][k] = threeD1[i][j][k] * threeD2[i][j][k];
            }
        }
    }
    printf("Multiplication:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("%d ", threeDResult[i][j][k]);
            }
        }
        printf("\n");
    }

    return 0;
}
