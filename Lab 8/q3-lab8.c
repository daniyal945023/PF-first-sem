#include <stdio.h>

#include <stdio.h>

int main(){
int arr1[5], arr2[5], newArr[10];
int flag = 0;
int count = 0;


printf("Enter 5 numbers for array 1:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter 5 numbers for array 2:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr2[i]);
    }

    for(int i = 0; i < 5; i++){
        flag = 0;
         for(int j = 0; j < 5; j++){
            if(arr1[i]==arr2[j]){
                   flag = 1;
            }
         }
         if(flag){
            newArr[count] = arr1[i];
            count++;
         }
    }

 
        printf("count is %d\t", count);
 


    return 0;
}