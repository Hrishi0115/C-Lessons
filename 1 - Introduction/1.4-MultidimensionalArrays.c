// type name[size1][size2]...[sizeN];

#include <stdio.h>

char vowels[2][5] = { // [rows][columns]
    {'A', 'E', 'I', 'O', 'U'},
    {'a', 'e', 'i', 'o', 'u'}
};

// int a[3][4] = {
//     {0,1,2,3},
//     {4,5,6,7},
//     {8,9,10,11}
// };

// int val = a[2][3];

// Alternatively

int a2[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};

int main() {
    int a[3][4] = {
    {0,1,2,3},
    {4,5,6,7},
    {8,9,10,11}
    };

    int val = a[2][3];

    printf("%d\n", val);
    return 0;
}