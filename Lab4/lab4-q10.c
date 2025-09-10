#include <stdio.h>

int main(){
    int balance;
    int withdrawalAmount;
    printf("Enter your bank balance before asking for withdrawal\n");
    scanf("%d", &balance);
    printf("Now enter the withdrawal amount\n");
    scanf("%d", &withdrawalAmount);
    printf("Bank Balance: %d\nWithdrawal Amount: %d\n", balance, withdrawalAmount);
    if(balance > withdrawalAmount && withdrawalAmount/500) {
        printf("Withdrawal Successful");
    } else {
        printf("Withdrawal Rejected");
    }
}