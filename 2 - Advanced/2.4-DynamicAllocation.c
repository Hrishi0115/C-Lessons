// Dynamic allocation of memory is very important in C - allows building complex data structures, e.g. linked lists
// Allocating memory dynamically helps us to store data without initially knowing the size of the data in the time we wrote the program

// To allocate a chunk of memory dynamically, we need to have a pointer ready to store the location of the newly allocated memory. 
// We can access memory that was allocated to us using that same pointer, and we can use that pointer to free the memory again, once we have finished
// using it.

// Let's assume we want to dynamically allocate a person structure
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char * name;
    int age;
} person;

// to allocate a new person in the myperson argument:

// int main() {
//     person *myperson = (person *) malloc(sizeof(person));


// // This tells the compiler that we want to dynamically allocate just enough to hold a person struct in memory and then return a pointer of type
// // person to the newly allocated data
// // the memory allocation (malloc) reserves the specified memory space. In this case, this is the size of person in bytes

// // we write (person *) before the call to malloc() because malloc() returns a "void pointer", which is a pointer that doesn't have a type.
// // writing (person *) in front of it is called typecasting, and changes the type of the pointer returned from malloc() to be person.
// // However it isn't strictly neccessary to write it like this as C will implicitly convert the type of the returned pointer to that of the pointer it is
// // assigned to (in this case myperson) if you don't typecast.

// myperson->name = "John";
// myperson->age = 27;

// free(myperson);

// // Note that the free does not delete the myperson variable itself, it simply releases the data that point to it. The myperson variable will still point
// // to somewhere in memory - but after calling myperson we are not allowed to access that area anymore. We must not use that pointer again until we allocate new
// // data using it.

// }

// Exercise

typedef struct {
  int x;
  int y;
} point;

int main() {
// //   point * mypoint = NULL;
  
//   // Dynamically allocate a new point struct which mypoint points to here

//   point *mypoint = (point *) malloc(sizeof(point));

  point *mypoint; // declares a pointer to a point struct - basically the * means that mypoint is a pointer variable

  printf("%p\n", mypoint);

//   mypoint = (point *) malloc(sizeof(point));
    

//   mypoint->x = 10;
//   mypoint->y =5 ;
//   printf("mypoint coordinates: %d, %d\n", mypoint->x, mypoint->y);

//   free(mypoint);
//   return 0;
}