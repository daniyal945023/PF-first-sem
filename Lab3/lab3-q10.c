#include <stdio.h>

int main(){
    int x = 2;
    int y = 5;
    int z = x;
    x = y;
    y = z;
    printf("x = %d and y = %d\n", x, y);

    printf("second program without third variable\n");
    int a = 7;
    int b = 9;
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %d and b = %d", a, b);

}
