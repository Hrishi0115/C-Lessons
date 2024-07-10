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

int main() {
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
    // However, by using dynamic memory allocation, one can allocate 
    
}