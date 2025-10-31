#include <stdio.h>
#include <string.h>







void encodeMessage(char str[]){
  int len = strlen(str);
  for(int i = 0; i < len/2; i++){
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }

  
  


for(int i = 0; i < len; i++){

     int ch = str[i]; 
     ch = ch ^ (1 << 1);
     ch = ch ^ (1 << 4);
    
     str[i] = ch;
    
}
    printf("Encoded message: %s\n", str);
}





void decodeMessage(char str[]){
int len = strlen(str);

   for(int i = 0; i < len; i++){

     int ch = str[i];
     ch = ch ^ (1 << 1);
     ch = ch ^ (1 << 4);
    
     str[i] = ch;
    
}


 for(int i = 0; i < len/2; i++){
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }

  printf("Decoded Msg: %s\n", str);
}

void quitProgram(){
  printf("Program exited\n");
}


int main(){
  char msg[100];
  int choice;

  do{

    
  printf("1.Encode Msg\n2.Decode Msg\n3.Exit\n");
  
  scanf("%d", &choice);
getchar();
  switch (choice)
  {
  case 1:
     printf("Enter message to encode: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';
    encodeMessage(msg);
    break;

    case 2:
    printf("Enter message to decode: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';
    decodeMessage(msg);
    break;

    case 3:
    quitProgram();
    break;
  
  default:
  printf("Invalid\n");
    break;
  }

} while(choice != 3);
  
    












    return 0;
}