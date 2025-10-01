#include <stdio.h>

int main() {
    int marks;
    printf("Enter marks\n");
    scanf("%d", &marks);
    if(marks>=50){
        if(marks>=85){
            printf("Passed with distinction");
        } else {
            printf("Just Passed");
        }
    } else {
        printf("Failed");
    }

    return 0;
}
