#include <stdio.h>

int main() {

    // int n = 0;
    // while (n < 10) {
    //     printf("%d\n",n);
    //     n++;
    // }

    // int n = 0;

    // while (1) { // 1 -> infinite loop
    //     printf("%d\n", n);
    //     n++;
    //     if (n == 10) {
    //         break;
    //     }
    // }    

    int n = 0;

    while (n < 10) {
        n++;

        if (n % 2 == 1) {
            // go back to the start of the while block (loop)
            continue;
        }

        printf("The number %d is even.\n", n);
    }

    return 0;
}

