#include <stdio.h>

int main(){
   char start,end;
   printf("Say starting letter of country\n");
   scanf(" %c", &start);
   switch(start){
               case 'A':
               case 'a':
                       printf("Please say ending letter\n");
                       scanf(" %c", &end);
                       switch(end){

                               case 'A':
                               case 'a':
                                       printf("Alaska\nAlbania\nAlgeria\n");
                                       break;
                                default:
                                printf("No such country\n");
                                break;
                       }
                      break;

                      case 'B':
                      case 'b':
                              printf("Please say ending letter\n");
                       scanf(" %c", &end);
                       switch(end){

                               case 'A':
                               case 'a':
                                       printf("Bulgaria\nBolivia\nBotswana\n");
                                       break;
                                default:
                                printf("No such country\n");
                                break;
   }
             break;
             default:
             printf("Please type correct letter");
             break;

   }
   
}