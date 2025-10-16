#include <stdio.h>

int main(){

    char userInput[100];
    char numArr[100];
    int j = 0;
    int sum = 0;

    printf("Enter text containing letters, digits, spaces, and special characters.\n");
    scanf("%[^\n]", userInput);

    for(int i = 0; userInput[i] != '\0'; i++){
        if(userInput[i] >= '0' && userInput[i] <= '9') {
            numArr[j] = userInput[i];
            sum += (userInput[i] - '0');
            j++;
            
        }
        }

        numArr[j] = '\0';


    
        

        printf("\nExtracted numbers: %s", numArr);
        printf("\nsum of numbers: %d", sum);
    






    return 0;
}