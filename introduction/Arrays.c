//  Here is a C program to implement and display 1D, 2D, and 3D arrays:
#include <stdio.h>

int main() {
    // 1D Array
    int oneD[5] = {1, 2, 3, 4, 5};
    printf("1D Array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", oneD[i]);
    }
    printf("\n");

    // 2D Array
    int twoD[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printf("\n2D Array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", twoD[i][j]);
        }
        printf("\n");
    }

    // 3D Array
    int threeD[2][2][2] = {
        {
            {1, 2},
            {3, 4}
        },
        {
            {5, 6},
            {7, 8}
        }
    };
    printf("\n3D Array:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("threeD[%d][%d][%d] = %d\n", i, j, k, threeD[i][j][k]);
            }
        }
    }

    return 0;
}
