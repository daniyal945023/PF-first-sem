#include <stdio.h>

int main(){
    int age;
    printf("Enter your age to check eligbility to vote\n");
    scanf("%d", &age);
    if(age >= 18) {
        printf("Eligible to Vote");
    } else {
        printf("Not Eligible");
    }
}


