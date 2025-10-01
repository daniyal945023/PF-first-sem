#include <stdio.h>

int main() {
    int num;
    printf("Enter number\n");
    scanf("%d", &num);
    if(num%2==0 && num%3==0){
        printf("number is divisible by 2 and 3");
    } else {
        printf("number not divisible by 2 and 3");
    }

    return 0;
}
