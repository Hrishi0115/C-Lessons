// static is a keyword in the C programming language. It can be used with variables and functions

// What is a static variable?

// By default, variables are local to the scope in which they are defined. Variables can be declared as static to increase their scope up to the file containing them.
// As a result, these variables can be accessed anywhere inside a file.

// #include <stdio.h>

// int runner() {
//     static int count = 0;
//     count++;
//     return count;
// }

// int main() {
//     printf("%d ", runner());
//     printf("%d ", runner());
// }

// What is a static function?

// By default, functions are global in C. If we declare a function with static, the scope of that function is reduced to the file containing it.

   #include <stdio.h>
   int sum (int num) {
        static int sum = 0;
        sum += num;
        return sum;
   }

   int main() {
       printf("%d ",sum(55));
       printf("%d ",sum(45));
       printf("%d ",sum(50));
       return 0;
   }