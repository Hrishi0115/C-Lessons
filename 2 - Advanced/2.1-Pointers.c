// Pointers are also variables and very important in C programming language.

// Used for: - strings, dynamic memory allocation, sending function arguments by reference, building complicated data structures, pointing to functions,
// and many more ...

// What is a pointer?

// A pointer is essentially a simple integer variable which holds a memory address that points to a value, instead of holding the actual value itself.

// The computer's memory is a sequential store of data, and a pointer points to a specific part of memory. Our program can use pointers in such a way that
// the pointers point to a large amount of memory

// Strings as pointers

char *name = "John";

// The above:
// 1. allocates a local (stack) variable called name, which is a pointer to a single character
// 2. causes the string "John" to appear somewhere in the program memory (after it is compiled and executed)
// 3. It initialises the `name` argument to point to where the J character resides at (which is followed by the rest of the string in the memory).

// Dereferencing

// Dereferencing is the act of referring to where the pointers points, instead of the memory address.
// We have already used dereferencing in array: the brackets operator - [0] for example, accesses the first item of the array.
// And since arrays are actually pointers, accessing the first item in the array is the same as dereferencing a pointer.
// Dereferencing a pointer is done using the asterisk operator *.

// If we want to create an array that will point to a different variable in our stack:

// define a local variable a

#include <stdio.h>

int main() {

    // define a local variable
    int a = 1;

    // define a pointer variable, and point it to `a` using the & operator

    int * pointer_to_a = &a;

    printf("The value a is %d\n", a);
    printf("The value of a is also %d\n", *pointer_to_a);

    return 0;
}