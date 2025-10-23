#include <stdio.h>

int main(){
    int arr1[5];
    int arr2[5];
    int isSame = 0;
    int unionArr[5];
    int newArr1;

    printf("Enter numbers in array 1\n");

    for(int i = 0; i < 5; i++){
        scanf("%d\n", &arr1[i]);
    }

   printf("Enter numbers in array 2");

   for(int j = 0; j < 5; j++){
    scanf("%d", &arr2[j]);
   }

for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
        if(arr1[i]==arr1[j]){
            isSame = 1;
            if(isSame){
                break;
                newArr1 = arr1[i];
            }
        }
    }
}





    return 0;
}