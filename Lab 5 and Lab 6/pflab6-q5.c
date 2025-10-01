#include <stdio.h>

int main(){
    int num = 4;
    int i;

    for(i = num-1; i; i-- ) {
      num *= i;
    }
    printf("%d", num);
}