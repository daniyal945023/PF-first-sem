#include <stdio.h>


int main() {
  int continentChoice;
  int countryChoice;
   printf("for continent choice, 1. Asia, 2.Europe\n");
   printf("Choose continent choice\n");
   scanf("%d", &continentChoice);
   switch(continentChoice) {
       case 1:
       printf("you chose Asia\n");
       printf("choose country choice, 1.Pakistan 2.India\n");
       scanf("%d", &countryChoice);
       switch (countryChoice) {
           case 1:
       printf("you chose Pakistan\n");
       break;
        case 2:
        printf("you chose India\n");
        break;
        default:
        printf("none");
        break;
   }
   break;
    case 2:
    printf("You chose Europe\n");
    printf("choose country choice, 1.France 2.Germany\n");
    scanf("%d", &countryChoice);
    switch(countryChoice) {
        case 1:
        printf("you chose France\n");
        break;
        case 2:
        printf("you chose Germany\n");
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
