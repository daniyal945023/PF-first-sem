#include <stdio.h>

int main(){
    int age;
    printf("Enter your age to get the ticket price.\n");
    scanf("%d", &age);
    if(age < 12) {
        printf("Ticket price: $200");
    } else if(age < 18) {
        printf("Ticket price: $300");
    } else if(age < 60) {
        printf("Ticket price: $500");
    } else {
        printf("Ticket price: $250");
    }
}


