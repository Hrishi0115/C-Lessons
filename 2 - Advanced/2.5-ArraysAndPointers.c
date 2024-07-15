#include <stdio.h>
#include <stdlib.h>

void example1() {
    char vowels[] = {'A','E','I','O','U'}; // remember, the name of an array (vowels) represents the address of the first element of the array
    char *pvowels = vowels; // points to the first element of the array

    // printf("%c\n", *(pvowels + 1));

    // int i;

    // for (i = 0; i < 5; i++) {
    //     printf("&vowels[%d]: %p, pvowels + %d: %p, vowels + %d: %p\n", i, &vowels[i], i, pvowels + i, i, vowels + i);
    // }

    // printf("%p\n", vowels);

    // printf("%p", pvowels + 1);

    int i;

    for (i = 0; i < 5; i++) {
        // print each memory address

        // pvowels + i

        printf("%p\n", pvowels + i);
    }
    
    // print the values

    for (i = 0; i < 5; i++) {
        // value given by vowels[i] or by dereferencing the pointer
        // printf("%c\n", vowels[i]);
        // // alternatively
        // printf("%c\n", *(pvowels + i));

        // or

        printf("%c\n", *(vowels + i));

    //     char v1 = vowels[i];
    //     char v2 = *(pvowels + i);

    //     if (v1 == v2) {
    //         printf("%s", "True\n");
    //     }
    
    }

}

// Dynamic Memory Allocation for Arrays

// 1. We can traverse an array using pointers
// 2. We can dynamically allocate (contiguous) memory using block pointers
// - can combine these to dynamically allocate memory for an array:

void example2() {
    // allocate memory to store five characters

    int n = 5;
    char *pvowels = (char *) malloc(n * sizeof(char));
    int i;

    pvowels[0] = 'A';
    pvowels[1] = 'E';
    *(pvowels + 2) = 'I';
    pvowels[3] = 'O';
    pvowels[4] = 'U';
    
    for (i = 0; i < n; i++) {
        printf("%c\n", pvowels[i]);
    }

    free(pvowels);

    // When is this useful? - When declaring an array, the number of elements that it would contain must be known beforehand. Therefore, in some scenarios
    // it might happen that the space allocated for an array is either less than the desired space or more.
    // However, by using dynamic memory allocation, one can allocate just as much memory as required by a program.
    // Moreover, unused memory can be freed as soon as it is no longer required by invoking the free() function.
    // On the downside, with dynamic memory allocation, one must responsibly call free() whenever relevant - otherwise memory leaks would occur.
    
}

// We conclude this tutorial by looking at dynamic memory allocation for a two-dimensional array - this can be generalised to n dimensions in a similar way.

// Unlike one-dimensional arrays, where we used a pointer, in this case we require a pointer to a pointer ...

void example3() {
    int nrows = 2;
    int ncols = 5;
    int i, j;

    // Allocate memory for nrows pointers

    char **pvowels = (char**) malloc(nrows * sizeof(char *)); // pointer to a pointer

    // pvowels is declared as a pointer to a pointer to a char
    // i.e. pvowels ultimately points to a memory location that contains addresses of other memory locations, which in turn contain characters char

    // pvowels points to a block of memory that can hold nrows pointers to char
    // +-----------------+        +-----------+-----------+
    // |   (pointer)     |  -->   |  pointer 1|  pointer 2|
    // +-----------------+        +-----------+-----------+
    // thus, pvowels points to the first element of an array of nrows pointers to char

    // For each row, allocate memory for ncols elements

    pvowels[0] = (char *) malloc(ncols * sizeof(char));
    pvowels[1] = (char *) malloc(ncols * sizeof(char));

    // For each row (each pointer in the array pointed to by pvowels) you allocate memory for ncols characters

    // pvowels[0] = (char *)malloc(ncols * sizeof(char));

    // malloc is a C function used to allocate a block of memory of the heap
    // malloc takes a single argument, which is the number of bytes to allocate, and returns a pointer to the beginning of the allocated memory block
    // if the allocation fails, malloc returns NULL

    // nrows * sizeof(char *) - here nrows represents the number of rows or the number of char * pointers we need
    // sizeof(char *) - calculates the size of a pointer to a char - usually 4 bytes on a 32-bit system
    // multiplying nrows by sizeof(char *) gives us the total amount of memory needed to store nrows pointers to char

    // typecasting with (char **) - change the void * generic pointer to char ** to match the type of pvowels

    // we've allocated memory for an array of nrows pointers to char

    // pvowels now points to the first element of this array of pointers

    // Visualisation:

    // 1. Initial State After Step 1: char **pvowels = (char **) malloc(nrows * sizeof(char *))
    // pvowels points to an  array of nrows (2) pointers, all initally NULL

    //     pvowels
    // +-----------------+        +-----------+-----------+
    // |   (pointer)     |  -->   |  NULL     |  NULL     |
    // +-----------------+        +-----------+-----------+

    // 2. After Allocating memory for each row

    for (i = 0; i < ncols; i++) {
        // pvowels[0] - initially NULL but the memory allocated is for a pointer to char - we want to allocate memory to what the pointer is pointing to
        // this pointer will point to the first element of an array of chars of ncols elements
        pvowels[i] = (char *) malloc(ncols * sizeof(char)); 
    }
    // pvowels
    // +-----------------+        +-----------+-----------+
    // |   (pointer)     |  -->   |  (ptr to char array)  |
    // +-----------------+        +-----------+-----------+
    //                              |           |
    //                              V           V
    //                          +------+    +------+
    //                          | char |    | char |
    //                          | array|    | array|
    //                          +------+    +------+

    // 1.5 - First Allocation:
    // pvowels[0] points to the first character of this newly allocated array
    //     pvowels
    // +-----------------+        +-----------+-----------+
    // |   (pointer)     |  -->   | pvowels[0]|   NULL    |
    // +-----------------+        +-----------+-----------+
    //                              |
    //                              V
    //                          +------+
    //                          | char |
    //                          | array|
    //                          +------+

    //     pvowels
    // +-----------------+        +-----------+-----------+
    // |   (pointer)     |  -->   | pvowels[0]| pvowels[1]|
    // +-----------------+        +-----------+-----------+
    //                              |           |
    //                              V           V
    //                          +------+    +------+
    //                          | char |    | char |
    //                          | array|    | array|
    //                          +------+    +------+



    pvowels[0][0] = 'A';
    pvowels[0][1] = 'E';
    pvowels[0][2] = 'I';
    pvowels[0][3] = 'O';
    pvowels[0][4] = 'U';

    pvowels[1][0] = 'a';
    pvowels[1][1] = 'e';
    pvowels[1][2] = 'i';
    pvowels[1][3] = 'o';
    pvowels[1][4] = 'u';

    for (i = 0; i < nrows; i++) {
        for(j = 0; j < ncols; j++) {
            printf("%c ", pvowels[i][j]);
        }

        printf("\n");
    }

    // Free individual rows
    free(pvowels[0]);
    free(pvowels[1]);

    // Free the top-level pointer
    free(pvowels);

}

int main() {
    int i, j;

    int nrows = 3;

    // define the 2D pointer variable

    int **pnumbers;

    // allocate memory for holding 3 rows of pointers to int
    pnumbers = (int **) malloc(nrows * sizeof(int *));

    // allocate memory for storing the individual elements in a row (2 elements per row)

    for (i = 0; i < nrows; i++) {
        pnumbers[i] = (int *) malloc(i+1 * sizeof(int));
    }
    
    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        /* TODO: free memory allocated for each row */
        free(pnumbers[i]);
    }

    free(pnumbers);

    return 0;
}