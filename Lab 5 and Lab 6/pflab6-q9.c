#include <stdio.h>

int main(){
    int num;
    printf("Enter number\n");
    scanf("%d", &num);
    for(int i = 1; i <= 12; i++){
        printf("%d\tX\t%d\t=\t%d\n", num, i, num*i);
    }




    return 0;
}