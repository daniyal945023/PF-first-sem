#include <stdio.h>

int main(){
    int arr[12];
    int removeNum;
    int newArr[12];
    int l=0;
    
    
    
    printf("Enter 12 numbers\n");

    for(int i=0; i < 12;i++){
        scanf("%d", &arr[i]);
        

    }

   
    
//{2,4,6,8,10,12}
    printf("enter number u want to remove\n");
    scanf("%d", &removeNum);

for(int j = 0; j < 12; j++){
    if(arr[j] != removeNum){
        
        newArr[l] = arr[j];
        l++;
        
    }
}

printf("{");
 for(int k=0; k < l;k++){
        printf("%d,", newArr[k]);
        

    }
    printf("}");
    return 0;
}



