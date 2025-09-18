#include <stdio.h>

int main(){
    int x;
    int y;

    printf("Enter valid x and y coordinates.\nx-coordinate:");
    scanf("%d", &x);
    printf("y-coordinate:");
    scanf("%d", &y);
    if(x == 0 && y == 0) {
        printf("Point lies in origin");
    } else if (x > 0 && y > 0) {
        printf("Point lies in Quadrant 1");
    } else if (x > 0 && y < 0) {
        printf("Point lies in Quadrant 4");
    } else if (x < 0 && y < 0) {
        printf("Point lies in Quadrant 3");
    } else if (x < 0 && y > 0) {
        printf("Point lies in Quadrant 2");
    } else {
        printf("Enter valid x and y coordinates");
    }
    
}