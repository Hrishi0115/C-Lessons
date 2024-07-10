// When a variable is created in C, a memory address is assigned to the variable

// the memory address is the location of where the variable is stored on the computer

// when we assign a value to the variable, it is stored in this memory address

// To access it, use the reference operator (&), and the result represents where the variable is stored:

#include <stdio.h>

int main() {

    int myAge = 43;

    printf("%p", &myAge); // need "%p" format specifier to print pointer values

    // prints 000000551D5FF96C

    // in hexadecimal form

    // &myAge is a pointer - a pointer stores the memory address of a variable as its value

    return 0;
}