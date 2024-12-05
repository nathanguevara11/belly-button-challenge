#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    OBJECTIVES
        - create 1d array
        - show memory allocation
        - show how to free
        - show what happens when you dont free properly
*/

void printArray(int *array, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);

    printf("\n");
}

void resetArrayToOne(int *array, int size) {
    for(int i = 0; i < size; i++)
        array[i] = 1;
}

int *oneDimensionalArray(int size) {

    int *newArray = malloc(size * sizeof(int));
    
    printArray(newArray, size);

    return newArray;
}

int main() {
    srand(time(NULL));

    printf("This is week 9 code\n");

    int size = 5;

    // objective 1
    printf("\nOBJECTIVE 1: create and pass dynamic arrays around\n");
    int *array = oneDimensionalArray(size);

    // misc step (lets reset the array to have only 1s)
    resetArrayToOne(array, size);
    printArray(array, size);

    // lets show how sizeof does not work with pointers (you lose that information)
    printf("\nOBJECTIVE 1.5: Sizeof problems\n");
    printf("Number of bytes allocated to an array of size %d is %ld\n", size, sizeof(array));

    // this shows that sizeof works nicely with static arrays
    int staticArray[5] = {1, 1, 1, 1, 1};
    printf("Number of bytes allocated to an array of size %d is %ld\n", size, sizeof(staticArray));

    // objective 2
        // to show memory leaks, you use valgrind (a terminal command that needs to be installed on any os)
        // codespaces has inherently. windows does not. macos is iffy (because idk if xcode has it by default)
    printf("\nOBJECTIVE 2: How to run Valgrind\n");
    printf("Command: 'valgrind --leak-check=full EXECUTABLE'\n");
    printf("\tEXECUTABLE is ./a.out or the name of you used the -o flag\n");

    // how to free
    printf("\nOBJECTIVE 3: Show how to free\n");
    free(array);        // this RETURNS the allocated memory to the heap (comment to see a mem leak)


    // 2d array if you do not free EVERYTHING (just the table)
    int **matrix = malloc(size * sizeof(int*));
    int *sizes = malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        int randomNumber = rand() % 10 + 1;     // give me a random size from 1 to 10
        matrix[i] = malloc(randomNumber * sizeof(int));
        sizes[i] = randomNumber;
    }

    // print the matrix!
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < sizes[i]; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // what happens if i free the table?
    //free(matrix);     // this is bad because it only frees at the top level

    for(int i = 0; i < size; i++) {
        free(matrix[i]);
    }

    free(matrix);
    
    return 0;
}