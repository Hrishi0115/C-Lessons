// 1. If you don't need to handle command-line arguments:

// int main() {
//     // code

//     return 0;
// }

// 2. If you need to handle command-line arguments:

#include <stdio.h>

int main(int argc, char *argv[]) {
    // argc: argument count
    // argv: argument vector (array of strings)

    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}

// e.g. gcc main.c arg1 arg2 arg3 -o main

// output

// Argument 0: C:\Users\hrish\C_Lessons\main.exe
// Argument 1: arg1
// Argument 2: arg2
// Argument 3: arg3

