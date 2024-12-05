#include <stdio.h>
#include <stdlib.h> // this is necessary for dynamic allocation (brief mention)

/*
    Objectives
        1. create a static 2d array
        2. create a dynamic 2d array
        3. modify either of these arrays
        4. matrix fun   
*/

void printMatrix(int **matrix, int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("Matrix at index [%d, %d] is: %d\n", i, j, matrix[i][j]);
        }
    }
}

void createStaticMatrix() {
    // in order to create any N dimensional matrix, we need all # dimensions
    // 2D = rows and columns
    // 3D = x/y/z
    // 4D = w/x/y/z

    int rows = 2;
    int columns = 3;

    int staticMatrix[2][3] = {
        {1, 1, 1},
        {1, 1, 1}
    };

    // printing 
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("Matrix at index [%d, %d] is: %d\n", i, j, staticMatrix[i][j]);
        }
    }
}

int **createDynamicMatrix(int rows, int columns) {
    int **matrix = malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        matrix[i] = malloc(columns * sizeof(int));

        for(int j = 0; j < columns; j++)
            matrix[i][j] = -1;
    }

    // printing
    printMatrix(matrix, rows, columns);

    return matrix;
}

void modifyMatrices(int **matrix, int rows, int columns) {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++) {
            if(i == j) {
                matrix[i][j] = -5;
            }
        }
    }

    printMatrix(matrix, rows, columns);
}

void matrixFun(int **matrix, int rows, int columns) {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // "flattening" the matrix
    int size = rows * columns;
    int *flattenedArray = malloc(size * sizeof(int));

    // resave the data (each row is appended after the previous row)
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            flattenedArray[i * columns + j] = matrix[i][j];

    // we converted a row by column matrix to an array of size = rows * columns
    for(int index = 0; index < rows * columns; index++) {
        printf("%d ", flattenedArray[index]);
    }

    free(flattenedArray);
}

int main(int argc, char **argv) {
    printf("Week 8 Code\n");

    // objective 1
    printf("\nOBJECTIVE 1: STATIC MATRIX\n");
    createStaticMatrix();

    // objective 2
    printf("\nOBJECTIVE 2: DYNAMIC MATRIX\n");
    int rows = 3;
    int columns = 3; 
    int **matrix = createDynamicMatrix(rows, columns);

    // objective 3
    printf("\nOBJECTIVE 3: MODIFY MATRICES\n");
    modifyMatrices(matrix, rows, columns);

    // objective 4
    printf("\nOBJECTIVE 4: MATRIX FUN\n");
    matrixFun(matrix, rows, columns);

    for(int i = 0; i < rows; i++)
        free(matrix[i]);

    free(matrix);

    return 0;
}