#include <stdio.h>

int main(){
    float temperature;
    printf("Enter temperature\n");
    scanf("%f", &temperature);
    if(temperature > 30) {
        printf("%.2f\u00B0C\n", temperature);
        printf("Hot Day");
    }
        else {
            printf("%.2f\u00B0C\n", temperature);
            printf("Pleasant Day");
        }
    }
