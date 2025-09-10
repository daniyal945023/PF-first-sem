#include <stdio.h>

int main(){
    int salary;
    int age;
    printf("Enter your age and salary to check elibility for loan.\n");
    printf("Your age\n");
    scanf("%d", &age);
    printf("Your salary\n");
    scanf("%d", &salary);
    
    if(salary >= 40000 && age >= 25) {
        printf("You are eligible for loan");
    } else {
        printf("Rejected for loan");
    }
}



