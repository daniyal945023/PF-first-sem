#include <stdio.h>

int main(){
    int x,y,z;
    printf("Enter value of x\n");
    scanf("%d", &x);
    printf("Enter value of y\n");
    scanf("%d", &y);
    printf("Enter value of z\n");
    scanf("%d", &z);
   
    if(x>y){
        if(x>z){
            printf("The largest value of x = %d",x);
        } else {
            printf("The largest value of z = %d", z);
        }
    } else {
        if(y>z){
            printf("The largest value of y = %d", y);
        } else {
            printf("The largest value of z = %d", z);
        }
    }



    return 0;
}