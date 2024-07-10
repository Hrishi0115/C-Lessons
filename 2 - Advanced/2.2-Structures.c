// C structures are special, large variables which contain several named variables inside.
// Structures are the basic foundation for objects and classes in C.
// Structures are used for:
// 1. Serialization of data
// 2. Passing multiple arguments in and out of functions through a single argument
// 3. Data structures such as linked lists, binary tress, and more.

// The most basic example of structures are points, which are single entities that contain two variables, x and y. Let's define a point:

struct Point {
    int x;
    int y;

};

void draw(int x, int y) {
    // draws a point at x, y
    // without Point struct, using the draw function requires two arguments - each for every coordinate
}

void draw2(struct Point p) {

}

// int main() {
//     struct Point p;
//     p.x = 10; // access the point's variable using the dot (.) operator
//     p.y = 5;

//     draw2(p);
// }

// Typedefs allow us to define types with a different name - which can come in handy when dealing with structs and pointers.
// In this case, we want to get rid of the long definition of a point structure. We can use the following syntax to remove the struct keyword from each
// time we want to define a new point

typedef struct {
    int x;
    int y;
} point;

// can now define a new point like this:

point p;

// Structures can also hold pointers - which allows them to hold strings, or pointers to other structures as well - which is their real power.
// For example, we can define a vehicle structure in the following manner.

typedef struct {
    char * brand; // created a char pointer called brand - currently points to nothing
    int model;
} vehicle;

int main() {
    vehicle mycar;
    mycar.brand = "Ford"; // since brand is a char pointer, the vehicle type can contain a string
    mycar.model = 2007;

    return 0;
}

