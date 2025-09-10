#include <stdio.h>
#include <string.h>

int main(){
    int num1;
    int num2;
    int operator;
    printf("Enter two numbers and desired operator to perform calculation\n");
    printf("For operator,\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\nresult = ");
    printf("Enter first number\n");
    scanf("%d", &num1);
    printf("Enter second number\n");
    scanf("%d", &num2);
    printf("Enter operator\n");
    scanf("%d", &operator);

     switch (operator)
     {
     case 1:
        printf("result = %d", num1 + num2);
        break;
     case 2:
        printf("result = %d", num1 - num2);
        break;
     case 3:
        printf("result = %d", num1 * num2);
        break;
     case 4:
        printf("result = %.2f", (float)num1 / num2);
        break;

     default:
     printf("Please select a number from 1 to 4");
        break;
     }

}