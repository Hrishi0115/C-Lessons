// Arrays are special variables uwhich can hold more than one value under the same variable name, organised with an index.

// this space, outside of any function, main, etc. is called the global space
// the global space is reserved for declarations and definitions, such as global variables and function prototypes
// any executable code, including function calls like printf, must be placed within a function

#include <stdio.h>

int main() {
    int numbers[10]; // define an array of 10 integers
    // populate the array
    numbers[0] = 10;
    printf("%d\n", numbers[0]);
    return 0;
}

// arrays can only have one type of variable, because they are implemented as a sequence of values in the computer's memory. 