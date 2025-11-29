#include <stdio.h>



void calculateRepayment(float loanAmt, float interestRate, int totalYears, int currYear, float extraPayments, float totalRepayment){
    

    float fixedInstallment = 12000.0;
    
    
    if(loanAmt <= 0 || currYear > totalYears){
        printf("total repayment: %.2f\n", totalRepayment);
        return;
    }
    
    loanAmt = loanAmt - (fixedInstallment+extraPayments);
    totalRepayment += fixedInstallment+extraPayments; 
    loanAmt = loanAmt + ((loanAmt * 5)/100); 
    
    

    printf("Year %d: Remaining Loan = %.2f\n",currYear, loanAmt);
    
    currYear++; 
    
    calculateRepayment(loanAmt, interestRate, totalYears, currYear,extraPayments, totalRepayment);
    


}



int main(){


calculateRepayment(100000, 5, 3, 1, 0, 0);

    

    return 0;
}