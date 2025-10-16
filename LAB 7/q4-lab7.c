#include <stdio.h>

int main(){



    
int arr[6];

printf("Enter 6 numbers\n");

    for(int i=0; i < 6;i++){
        scanf("%d", &arr[i]);
        
    }

int length = sizeof(arr)/sizeof(arr[0]);
int lastIndex = arr[length-1];

for(int i = length-1; i >0; i--){

    arr[i] = arr[i-1];
    
}

arr[0] = lastIndex;

printf("output:\n");
printf("{");
for(int i =0; i<length;i++){
printf("%d,", arr[i]);
}

printf("}");


return 0;
}