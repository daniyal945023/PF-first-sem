#include <stdio.h>

int main(){
int sum = 0;
int arrPL[10];

 printf("Enter 10 numbers profit and/or loss\n");

    for(int i=0; i < 10;i++){
        scanf("%d", &arrPL[i]);
        
    }



for(int i = 0; i < 10;i++){

    if(arrPL[i] > 0) {
        sum += arrPL[i];
    }

}
printf("%d", sum);

    return 0;
}