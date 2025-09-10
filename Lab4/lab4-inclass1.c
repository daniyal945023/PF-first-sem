#include <stdio.h>
#include <string.h>

int main(){
    char email[20];
    char password[20];
    printf("Enter your email\n");
    scanf("%s", &email);
    if(strcmp(email, "admin@gmail.com") == 0) {
          printf("Now enter password\n");
          scanf("%s", &password);
          if(strcmp(password, "admin123") == 0) {
            printf("Access Granted");
          } else {
            printf("Password Incorrect\nAccess Denied");
          }

          
    } else {
        printf("Incorrect Email\nAccess Denied");
    }
}