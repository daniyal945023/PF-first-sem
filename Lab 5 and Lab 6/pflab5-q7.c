#include <stdio.h>
//num1<num2 and num3<num2
int main(){
    int num1, num2, num3;
    printf("Enter 3 numbers\n");
    scanf("%d",&num1);
    scanf("%d",&num2);
    scanf("%d",&num3);

    num1<num2 && num1<num3 ? printf("%d is smallest", num1) : 
    (num2<num1 && num2<num3 ? printf("%d is smallest", num2) : printf("%d is smallest", num3)); 

    return 0;
}