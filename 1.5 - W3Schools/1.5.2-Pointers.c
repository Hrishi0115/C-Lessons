// from 1.5.1, we know that we can get the memory address of a variable with the reference operator &

#include <stdio.h>

void example1() {
    int myAge = 43;

    printf("%d\n", myAge); // value
    printf("%p\n", &myAge); // memory address

}

// a pointer is a variable that stores the memory address of another variable as its value

// a pointer variable points to a data type (like int) of the same type, and is created with the * operator

void example2() {
    int myAge = 43;
    int* ptr = &myAge; // a pointer variable, with the name ptr, that stores the address of myAge

    printf("%d\n", myAge); // output the value of myAge (43)

    printf("%p\n", &myAge); // outputs the memory address of myAge

    // equivalently

    printf("%p\n", ptr); // outputs the memory address of myAge with the pointer


    // here, we create a pointer variable, ptr, that points to an int variable myAge. Note, the type of the pointer has to match the type of
    // variable that it is pointing to

}

void dereference() {
    // Above, we used the pointer variable to get the memory address of a variable (used together with the & reference operator)

    // You can also get the value of the variable the pointer points to, by using the * operator (the dereference operator)

    int myAge = 43; // variable declaration
    int* ptr = &myAge; // pointer declaration

    // reference: output the memory address of myAge with the pointer (0x....)

    printf("%p\n", ptr);

    // dereference: output the value of myAge with the pointer (43)

    printf("%d\n", *ptr);

    // The * sign can be confusing here, as it does two different things:

    // 1. when used in declaration (int* ptr) it creates a pointer variable
    // 2. When not used in declaration, it acts as a deference operator (*ptr)

    // two ways to declare pointer variables in C:
    // 1. int* myNum = &myNum;
    // 2. int *myNum = &myNum;
}



int main() {
    dereference();

    return 0;
}