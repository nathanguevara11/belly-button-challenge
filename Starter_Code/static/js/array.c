#include <stdio.h>
#include <stdlib.h>


/*
    - ARRAY OBJECTIVES
        - initialization
        - traversal
        - prefix sizes vs undeclared sizes
        - static vs dynamic (brief rundown)
        - force a segfault
*/

void setDefaultValues(int *list_of_items) {
    for(int i = 0; i < 10; i++) {
        list_of_items[i] = 0;
    }
}

// Unable to do sizeof(list_of_items) because it will return the size of the pointer which is 8 bytes
// It is required to pass in the size parameter because the array will "decay" into a pointer (so you lose the size information)
void printArray(int *list_of_items, int size) {
    // here we have garbage values
    for(int i = 0; i < size; i++) {
        printf("Value of array at index %d is: %d\n", i, list_of_items[i]);
    } 
}

// Unable to return int[] because the return value will "decay" from type int [N] to int *
// this is C specific behavior (not C++ which I was basing the recording from)
void practiceInitialization() { 
    printf("\nFirst Objective\n");

    int list_of_items[10];

    // here we have garbage values
    printArray(list_of_items, 10);

    // here we set the default values
    setDefaultValues(list_of_items);

    // print after resetting the array 
    printArray(list_of_items, 10);
}

void letsTraverse() { 
    // for loop is used within practice initialization
    printf("\nSecond Objective \n");
    int list_of_items[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // sizeof -> returns number of bytes of THAT address
    //      sizeof(list_of_items) = sizeof(int) * the number of elements inside that array
    //      sizeof(list_of_itesm[0]) = sizeof(int) = 4
    int length = sizeof(list_of_items) / sizeof(list_of_items[0]);

    int i = 0;
    while(i < length) {
        printf("Value of array at index %d is: %d\n", i, list_of_items[i]);
        i++;
    }

    printf("\n"); 

    // the following code will print the same as above
    printArray(list_of_items, length);
}

// This is to show the difference between setting a size and not setting a size (the array can't be resized but different indices can be accesssed)
void sizeInconsistency() {
    printf("\nThird objective\n");
    
    // set size
    int predetermined_array[5] = {1, 2};

    // undetermined size
    int unknown_sized_array[] = {0, 0};

    // prints additional elements because the size was set to 5
    printArray(predetermined_array, sizeof(predetermined_array) / sizeof(predetermined_array[0]));
    
    printf("\n");
    
    // does not print additional elements because the "size" can only be 2
    printArray(unknown_sized_array, sizeof(unknown_sized_array) / sizeof(unknown_sized_array[0]));
}

// This is to show the difference between static and dynamic arrays (exposure of dynamic from lab 3 and static from File I/O with char arrays)
void staticVsDynamic() {
    printf("\nFourth objective\n");

    // static
    int static_array[5] = {1, 2, 3, 4, 5};

    // dynamic
    int *dynamic_array = (int *)malloc(5 * sizeof(int));
    for(int i = 0; i < 5; i++) {
        dynamic_array[i] = i + 1;
    }

    // print static
    printArray(static_array, 5);

    // print dynamic
    printArray(dynamic_array, 5);

    // free the memory (because we dynamically allocated it)
    free(dynamic_array);
}

// So after digging into C a bit more, I found that the following code will not cause a segfault because C is dumb
// Upon entering what should be an invalid index, C will start something called "unknown behavior" which is not a segfault but CAN BE one
// I dont know why this is a thing but here's a link: https://stackoverflow.com/questions/27269265/segmentation-fault-doesnt-come-up-immediately-after-accessing-out-of-bound-memo
void forceSegFault() {
    printf("\nFourth objective\n");

    int arr[10];
    for (int i = 10; i <= 15; i++) {
        printf("Value of array at index %d is: %d\n", i, arr[i]);
    }
}

int main(int argc, char **argv) {
    printf("This is week 7 material\n");

    // task 1
    practiceInitialization();

    // task 2
    letsTraverse();

    // task 3
    sizeInconsistency();

    // task 4
    staticVsDynamic();

    // task 5
    forceSegFault();

    return 0;
}