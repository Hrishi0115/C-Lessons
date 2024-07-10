#include <stdio.h>
#include <string.h>

// Strings in C are actually arrays of characters

// we will use pointers now but explain in detail in pointers lesson

int main() {
    char *name = "John Smith"; // this method creates a string which we can only use for reading, if we need a string which can be manipulated, we will need
    // to define it as a local character array

    char name2[] = "John Smith";

    // this notation is different because it allocates an array variable so we can manipulate it
    // the empty brackets notation [] tells the compiler to calculate the size of the array automatically
    // same as

    char name3[11] = "John Smith"; // we need to add 1 (since `John Smith` is 10 characters) for the string termination - a special character equal to 0 which
    // indicates the end of a string

    // String Formatting

    int age = 27;

    printf("%s is %d years old.\n", name, age);

    // String Length
    char *name4 = "Nikhil";
    printf("%d\n", strlen(name4));

    // String comparison

    char *name5 = "John";

    if (strncmp(name5, "John", strlen(name5)) == 0) {
        printf("Hello %s!\n", name5);
    } else {
        printf("You are not %s. Go away.\n", name5);
    }

    // String Concatenation

    // strncat appends first n characters of src to the destination string where n is the maximum number of characters to be appended, i.e. n = min(n,length(src))

    char dest[20] = "Hello";
    char src[20] = "World";

    // strncat(dest, src, 3);
    // printf("%s\n", dest);
    strncat(dest, src, 5);
    printf("%s\n", dest);

}