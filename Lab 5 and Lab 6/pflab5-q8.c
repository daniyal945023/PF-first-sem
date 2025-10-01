#include <stdio.h>

int main(){
    int num;
    printf("Enter number\n");
    scanf("%d", &num);
    
    int result = num ^ (1 << 1);
    
    printf("%d", result);

}