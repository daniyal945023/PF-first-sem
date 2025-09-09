
// Area and Perimeter of Rectangle


#include <stdio.h>

int main(){
    int length;
    int width;
    printf("Enter length and height of the Rectangle\n");
    scanf("%d %d", &length, &width);
    int areaRec = length*width;
    int perimeterRec = (2*length)+(2*width);
    printf("The area is %d and the perimeter is %d", areaRec, perimeterRec);
}


