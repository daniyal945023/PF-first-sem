#include <stdio.h>

int main(){
    int i, youngest;
    int age[8];

    printf("Enter age of 8 participants\n");

    for(i = 0; i < 8; i++){
        scanf("%d", &age[i]);
    if(age[i] <= age[0]){
        youngest = age[i];
        
    }

    
    }

    printf("youngest is %d\n", youngest);







    return 0;
}