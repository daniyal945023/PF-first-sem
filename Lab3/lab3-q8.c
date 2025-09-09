#include <stdio.h>

int main(){
    float sub1Marks;
    float sub2Marks;
    float sub3Marks;
    printf("Enter marks for 3 subjects.Each subject has marks out of 100.\n");
    scanf("%f %f %f", &sub1Marks, &sub2Marks, &sub3Marks);
    float marksObtained = sub1Marks+sub2Marks+sub3Marks;
    float percentage = marksObtained*(100.0/300.0);
    printf("the result is %.2f %%", percentage);
}