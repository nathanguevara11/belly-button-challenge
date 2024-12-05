#include <stdio.h>
#include <stdlib.h>     // this is for DMA
#include <string.h>     // new stuff in the lecture

/*
    Objectives:
        1. difference between char array and char pointer
        2. modifying the above
        3. fgets + getchar
        4. string library functions
*/

void printString(char *string) {
    // this doesnt work because we've decayed and lost information
    // in other words, we only the size of the pointer itself
    int size = sizeof(string) / sizeof(string[0]);

    // what we need is a way to get the size of the entire array or "consecutive" memory addresses
        // the second argument in the loop can check for "null terminator" instead of size

    printf("Printing %s individually\n", string);
    for(int i = 0; string[i] != '\0'; i++)
        printf("String[%d] is %c\n", i, string[i]);

    printf("\n");
}

void modifyString(char *string) {
    string[0] = 'B';

    printString(string);
}

void viewInputStreamBehavior() {
    int maxLimit = 10;

    char arr[1024];
    fgets(arr, maxLimit, stdin);

    // the "maxLimit" character will always be null terminator IF the input is larger than max limit
    printf("The contents of arr will be: %s\n", arr);

    // how do we see what was left (if there any?)
        // we use getchar()
    int letter = 0;
    while( (letter = getchar()) != '\n') 
        printf("Remaining letter in input stream is: %c\n", letter);
}

void stringLibraryExamples() { 
    char string1[1024] = "Pokemon";
    char string2[1024] = "Gotta Catch Em all";

    // first case is strcmp
        // reminder, the vlaues of strcmp is negative, zero, or positive
        // where negative means string1 goes first
        // zero means equal
        // positive means string2 goes first
    int value = strcmp(string1, string2);
    printf("The comparison result of string1 vs string2 is: %d\n", value);

    // second case is strcat
    strcat(string1, string2);
    printString(string1);
}

int main(int argc, char **argv) {
    printf("In Class code for Week 10\n");

    printf("\nObjective 1\n");

    // three different ways to create strings
    char string1[10] = "Pikachu";
    char *string2 = "Pikachu";      // this is the one approach you want to avoid at all times
    char *string3 = malloc(10 * sizeof(char));
    strcpy(string3, "Pikachu");

    printString(string1);
    // printString(string2);
    // printString(string3);


    // printf("\nObjective 2\n");
    // modifyString(string1);
    // //modifyString(string2);      // this is bad. String 2 is a literal and causes read only access to flag and breaks compilation
    // modifyString(string3);

    // printf("\nObjective 3\n");
    // //viewInputStreamBehavior();
    
    // printf("\nObjective 4\n");
    // stringLibraryExamples();

    return 0;
}