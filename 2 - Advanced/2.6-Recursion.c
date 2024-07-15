// Recursion occurs when a function contains within it a call to itself.

// Recursion can result in very neat, elegant code that is intuitive to follow.

// It can also result in a very large amount of memory being used if recursion gets too deep.

// Common examples where recursion is used:
// Walking recursive data structures such as linked lists, binary trees, etc.; exploring possible scenarios in games such as chess

// Recursion always consists of of two main parts: a terminating case that indicates when the recursion will finish and a call to itself that must make
// progress towards the terminating case.

// E.g. this function performs multiplication by recursively adding:

#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y) {
    // unsigned - can only hold positive numbers
    
    if (x == 1) {
        // Terminating case
        return y;
    }

    else if (x > 1) {
        // Recursive step

        return y + multiply(y, x - 1);
    }

    // catch scenario when x is zero
    return 0;
}

int main() {
    printf("3 x 5 is %d", multiply(3,5));
    return 0;
}


// Exercise - factorial
// 0! = 1

int factorial(int x) {
    // terminating case
    if (x == 1) {
        return 1;
    }

    else if (x > 1) {
        // recursive step
        return x * factorial(x - 1);
    }

    // catch scenario 0!

    return 1;
}