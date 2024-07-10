// What if we pass pointers to values instead of values themselves as function arguments

// this will allow us to give functions control over the variables and structures of the parent functions and not just a copy of them, thus
// directly reading and writing the original object

#include <stdio.h>

// void addone(int n) {
//     // n is a local variable which only exists in within the project scope
//     n++; // therefore incrementing it has no effect

// }

// int main() {
//     int n;
//     printf("%d\n", n);
//     addone(n);
//     printf("%d\n", n);
// }

// However this will work

void addone(int *n) {
    // n is a pointer which points  to a memory-address outside of the function scope

    (*n)++; // increase the value of the int that the pointer is pointing to
}

int main() {
    int n = 10;
    // printf("%p\n", &n);
    printf("%d\n", n);
    addone(&n); // here addone receives a pointer to the variable n as an argument, and then it can manipulate n as it knows where it is in memory
    printf("%d\n", n);
}

// Pointers to structures

// function to move a point forward in both x and y directions, called move

typedef struct {
    int x;
    int y;
} point;

// void move(point *p) {
//     // *p refers the the point object that the pointer *p is pointing towards
//     (*p).x++;
//     (*p).y++;
// }

// However, if we wish to dereference a structure and access one of it's internal members, we have a shorthand syntax for that, because this operation
// is widely used in data structures:

void move(point *p) {
    p->x++;
    p->y++;
}

// Exercise

typedef struct {
    char *name;
    int age;
} person;

void birthday(person *p) {
    p->age++;
}