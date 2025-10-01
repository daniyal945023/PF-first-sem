#include <stdio.h>


int main() {
   int deviceChoice;
   int brandChoice;
   printf("for device choice, 1. Phone, 2. Laptop\n");
   printf("Choose device choice\n");
   scanf("%d", &deviceChoice);
   switch(deviceChoice) {
       case 1:
       printf("you chose Phone\n");
       printf("choose brand choice, 1.Samsung 2. Apple\n");
       scanf("%d", &brandChoice);
       switch (brandChoice) {
           case 1:
       printf("you chose Samsung\n");
       break;
        case 2:
        printf("you chose Apple\n");
        break;
        default:
        printf("none");
        break;
   }
   break;
    case 2:
    printf("You chose Laptop\n");
    printf("choose brand choice, 1.Dell 2.HP\n");
    scanf("%d", &brandChoice);
    switch(brandChoice) {
        case 1:
        printf("you chose Dell\n");
        break;
        case 2:
        printf("you chose HP\n");
        break;
        default:
        printf("none");
        break;
    }
    break;
    default:
    printf("none\n");
    break;
   }
   

    return 0;
}
