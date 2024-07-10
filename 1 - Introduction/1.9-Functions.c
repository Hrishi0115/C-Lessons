// Functions can either receive a fixed or variable amount of arguments

//  Functions can only return one value, or return no value

#include <stdio.h>

 int foo (int bar) {
    return bar * 2;
 }

 int main() {
    int x = foo(131);
    printf("%d\n", x);
    return 0;
 }