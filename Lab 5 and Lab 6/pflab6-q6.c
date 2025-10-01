#include <stdio.h>

int main(){
    int num = 3;
    int i = 0;
    int isPrime = 1;

    if(num <= 1) {
        isPrime = 0;
    } else {
        for(i = 2; i < num; i++) {
            if(num%i==0){
                isPrime = 0;
                break;
            }
        }
    }
    
if(isPrime) {
    printf("%d is prime", num);
} else {
    printf("%d is not prime", num);
}

    return 0;
}