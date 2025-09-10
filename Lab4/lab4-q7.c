#include <stdio.h>

int main(){
    int passwordInput;
    printf("Enter password to get access\n");
    scanf("%d", &passwordInput);
    if(passwordInput == 1234) {
        printf("Access Granted");
    } else {
        printf("Access Denied");

    }
}