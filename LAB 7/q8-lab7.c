#include <stdio.h>

int main(){

int arr[10] = {1,3,2,7,9,11,13,15,17,19};

printf("Enter 10 numbers to check ascending order\n");

    for(int i=0; i < 10;i++){
        scanf("%d", &arr[i]);
        
    }



int ascendingOrder = 1;

for(int i = 1; i <10; i++){
    if(arr[i-1] > arr[i]){//0<1,1<2,2<3,3<4,4<5,5<6,6<7,7<8,8<9,9<10
        ascendingOrder = 0;
        break;
    } 
    
}

if(ascendingOrder == 1){
    printf("ascending order\n");
} else {
    printf("not ascending order\n");
}



    return 0;
}