#include <stdio.h>

int main(){

    int asciiVal = 65;
//ascii 65 to 90 for A to Z
for(int i = 0; i < 5; i++){
    for(int j = 0; j < i; j++){
            printf("%c ", asciiVal);
            asciiVal++;
            if(asciiVal < 65 || asciiVal > 90){
                break;
            }
    }
    printf("\n");
}




    return 0;
}