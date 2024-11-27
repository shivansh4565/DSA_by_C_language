#include <stdio.h>

#define MAX_SIZE 100

// Structure to store sparse matrix in COO format
typedef struct {
    int row;
    int col;
    int value;
} Element;

// Function to print sparse matrix in COO format
void printSparseMatrix(Element matrix[], int nonZeroCount) {
    printf("Row   Column   Value\n");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d    %d       %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    int rows, cols, nonZeroCount = 0;
    
    // Get matrix dimensions
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    int matrix[rows][cols];
    
    // Get matrix values
    printf("Enter the elements of the matrix (row by row):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Count non-zero elements and store them in the Element array
    Element sparseMatrix[MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[nonZeroCount].row = i;
                sparseMatrix[nonZeroCount].col = j;
                sparseMatrix[nonZeroCount].value = matrix[i][j];
                nonZeroCount++;
            }
        }
    }

    // Print the sparse matrix in COO format
    printf("Sparse Matrix in COO format:\n");
    printSparseMatrix(sparseMatrix, nonZeroCount);
    
    return 0;
}
