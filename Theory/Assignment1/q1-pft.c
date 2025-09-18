#include <stdio.h>
#include <string.h>


int main(){
    int transactionAmount;
    char customerName[10];
    char transactionLocation[10];
    int transactionNum = 0;
    int dailyLimit = 10000;
    char defaultLocation[] = "Pakistan";
    int numOfTransactionLimit = 3;
    int minutes = 60;
    printf("Input Transaction Details in order, name:\n");
    scanf("%s", &customerName);
    printf("amount:");
    scanf("%d", &transactionAmount);
    printf("location:");
    scanf("%s", &transactionLocation);
    printf("Name: %s Amount: %d Location: %s\n", customerName, transactionAmount, transactionLocation);
    transactionNum++;
    if(transactionAmount > dailyLimit || strcmp(transactionLocation, defaultLocation) == 1 ) {
        printf("FLAGGED\n");
    } else {
        printf("Transaction is clear\n");
    }
    if (transactionNum > numOfTransactionLimit) {
        printf("WARNING, daily transaction limit exceeded. FLAGGED\n");
    }

printf("Input Transaction Details in order, name:\n");
    scanf("%s", &customerName);
    printf("amount:");
    scanf("%d", &transactionAmount);
    printf("location:");
    scanf("%s", &transactionLocation);
    printf("Name: %s Amount: %d Location: %s\n", customerName, transactionAmount, transactionLocation);
    transactionNum++;
    if(transactionAmount > dailyLimit || strcmp(transactionLocation, defaultLocation) == 1 ) {
        printf("FLAGGED\n");
    } else {
        printf("Transaction is clear\n");
    }
    if (transactionNum > numOfTransactionLimit) {
        printf("WARNING, daily transaction limit exceeded. FLAGGED\n");
    }

    // .
    // .
    // .
    // .
    // . the code continues in a loop
}