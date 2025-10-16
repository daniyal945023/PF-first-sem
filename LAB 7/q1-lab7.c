#include <stdio.h>

int main(){
	int employeeIdArr[12];
	int i;
	
	printf("Enter employee ID\n");
	for(i = 0; i < 12; i++){
		scanf("%d", &employeeIdArr[i]);
		
	}
		int empIdCheck;
	int IdExists =0;
	int j;
	printf("Enter employee ID to check\n");
		scanf("%d", &empIdCheck);

	for(j = 0; j < 12; j++){
	
		if(empIdCheck == employeeIdArr[j]) {
			IdExists = 1;
			
			
		} 
	
	}
	
	if(IdExists!= 0) {
		printf("ID %d exists\n", empIdCheck);
	} else {
		printf("ID does not exist\n");
	}
	
	
	
	
	
	
	return 0;
}
