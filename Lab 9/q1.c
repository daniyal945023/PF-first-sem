#include <stdio.h>
float interest = 0;
float calculateInterest(int principal, float rate, int time){
 interest = (principal * rate * time)/100; 
	return interest;
}

float updateBalance(float currentBalance, float interest){
	float newBalance = currentBalance + interest;
	return newBalance;
	
}




int main(){
	printf("Enter principal amount, rate in %% and time in years\n");
	printf("Interest is %.2f\n", calculateInterest(5000, 4, 5));
	printf("New Updated balance is %.2f\n", updateBalance(7000, interest));
	
	
	return 0;
}
