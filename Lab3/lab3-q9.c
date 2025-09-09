#include <stdio.h>

int main(){
    char userName[10];
    int age;
    printf("Enter your user name and age.\n");
    scanf("%s %d", userName, &age);
    printf("Your username is: \"%s\" and age is: \"%d\".", userName, age);
}