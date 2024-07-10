// You can also use pointers to access arrays

#include <stdio.h>

void part1() {
    int myNumbers[4] = {25,50,75,100};

    int i;

    for (i=0; i < 4; i++) {
        printf("%p\n", &myNumbers[i]);
    }

    /* output
    00000044DEFFFE00
    00000044DEFFFE04
    00000044DEFFFE08
    00000044DEFFFE0C
   */
   // Note that the last number of each elements' memory address is different with an addition of 4 - because the size of an int is typically 4 bytes. 
    // Create an int variable
    int myInt;

    // Get the memory size of an int
    printf("%lu", sizeof(myInt));
}

// How are Pointers related to Arrays?

// In C, the name of an array is actually a pointer to the first element of the array.

// That is, the memory address of the first element is the same as the name of the array

void part2() {
    int myNumbers[4] = {1,2,3,4};

    // get the memory address of the myNumbers array;

    printf("%p\n", &myNumbers);

    // get the memory address of the first array element;

    printf("%p\n", &myNumbers[0]);

    // They are the same!

    // Therefore, you can work with arrays through pointers!

    // How? Since myNumbers is a pointer to the first element in myNumbers, you can use the * operator to access it

    // get the value of the first element in myNumbers
    printf("%d\n", *myNumbers);

    // to access the rest of the elements in myNumbers, you can increment the pointer/array (+1, +2, etc)
    printf("%d\n", *(myNumbers + 1));

    // myNumbers + 1: (remember myNumbers is a pointer) moves the pointer to the next element of the array - this works because in pointer arithmetic,
    // adding 1 to a pointer of type `int*` moves the pointer by the size of one int

    // or loop through it

    // int *ptr = myNumbers;
    int i;

    for (i=0; i < 4; i++) {
        printf("%d\n", *(myNumbers + i));
    }

    // it is also possible to change the value of array elements with pointers

    *myNumbers = 5; // change the value of the first element to 5

    *(myNumbers + 1) = 6; // change the value of the second element to 6

    for (i=0; i < 4; i++) {
        printf("%d\n", *(myNumbers + i));
    }
}

int main() {
    part2();
    return 0;
}

// This way of working with arrays might seem a bit excessive, especially with simple arrays like above.
// However, for large arrays, it can be much more efficient to access and manipulate arrays with pointers.
// It is also considered faster and easier to access two-dimensional arrays with pointers
// and since strings are actually arrays, you can also use pointers to access strings
// Important to handle pointers with care - possible to overwrite other data stored in memory
