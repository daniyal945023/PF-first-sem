#include <stdio.h>

int total;

float finalBill = 0;
int j;

float calculateTotal(float prices[], int size){
	 total = 0;
	for(int i = 0; i < size; i++){
		total = total + prices[i];
	}
	
	return total;
}

void applyDiscount(){
	
	if(total > 5000){
		finalBill = total - (total * 0.1);
	} else {
		printf("No discount\n");
	}
	
}


void printBill(){
	printf("Final bill: %.2f\n", finalBill);
}


int main(){
	float pricesArr[5];
	for(j = 0; j < 5; j++){
		printf("Enter price for product\n");
		scanf("%f", &pricesArr[j]);
	}
	
	
	printf("\nThe total of all prices is %.2f\n", calculateTotal(pricesArr, 5));
	applyDiscount();
	printBill();
	
	
	return 0;
}
