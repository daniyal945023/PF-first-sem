#include <stdio.h>

int main(){
    int marks[10];
    int i;
    int sum = 0;
    float avg;

    printf("Enter marks of each student\n");

    for(i = 0; i < 10; i++){
        scanf("%d", &marks[i]);
        sum += marks[i];

    }

    
    avg = sum/10.00;
    printf("%f", avg);






    return 0;
}