#include <stdio.h>
#include <string.h>


int main(){
    int age;
    char nationality[20];
    printf("Enter your age and nationality to see whether you are eligible to vote or not\n");
    printf("Your age\n");
    scanf("%d", &age);
    printf("Your Nationality\n");
    scanf("%s", &nationality);
    if(age >= 18 && strcmp(nationality, "Pakistani") == 0) {
        printf("You are eligible to vote");
    } else {
        printf("You are not eligible to vote");
    }
}