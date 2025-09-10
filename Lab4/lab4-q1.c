#include <stdio.h>

int main(){
    int billInput;
    printf("Enter bill amount\n");
    scanf("%d", &billInput);
    if(billInput > 5000){
        int discount = billInput*0.1;
        int finalPayableAmount = billInput - discount;
        printf("The final payable amount is %d", finalPayableAmount);
    } else{
        printf("The final payable amount is %d, no discount as bill is less than 5000", billInput);
    }
}

