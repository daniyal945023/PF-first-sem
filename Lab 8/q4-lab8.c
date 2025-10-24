#include <stdio.h>

int main(){

int days = 7, shifts = 3;
int arr[days][shifts];
float avg;
int total = 0;

for(int i  =0; i < days;i++){
      for(int j = 0; j < shifts; j++){
        
printf("Enter values for arr[%d][%d]\n", i, j);
        scanf("%d", &arr[i][j]);
      }
                      
}

for(int i = 0; i < days; i++){
    for(int j = 0; j < shifts; j++){
        printf("The value of arr[%d][%d] is %d\n",i, j, arr[i][j]);
    }
}

for(int i = 0; i < days; i++){
    total = 0;
    for(int j = 0; j < shifts; j++){
        total = total + arr[i][j]; 
    }
    avg = total/3.0; 
    printf("the avg is %.2f\n", avg);
}





    return 0;
}