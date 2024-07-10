#include <stdio.h>

// Integers - whole numbers which can be either positive or negative. Defined using char, int, short, long or long long.
// Unsigned integers - whole numbers which can only be positve. Defined using unsigned char, unsigned int, unsigned short, unsigned long, unsigned long long
// Floating point numbers - real numbers (numbers with fractions). Defined using float and double
// Structures ...

// the different types of variables defined their bounds - a char can range only from -128 to 127,
// a long from -2,147,483,648 to 2,147,483,647

// Note: C does not have a boolean type. Usually, it is defined using the following notation:
#define BOOL char // common convention in C programming to use uppercase for macro names 
#define FALSE 0
#define TRUE 1

// #define is a preprocessor directive in C - the preprocessor tool runs before the actual compliation of the code starts.
// the #define directive is used to create macro definitions or symbolic constants
// BOOL: this is a macro name (symbolic constant) being defined. 
// essentially, #define BOOL char makes BOOL a new name for the char data type
// #define FALSE 0: FALSE is another macro name - after this definition, every occurence of FALSE in the code will be replaced by 0 during preprocessing

void bool_demonstration() {

    BOOL isFinished = FALSE;
    if (10 > 5) {
        isFinished = TRUE;
    }

}

// C uses an array of characters to define strings, explained later ...

void variables() {
    int foo;
    int bar = 1;
}


