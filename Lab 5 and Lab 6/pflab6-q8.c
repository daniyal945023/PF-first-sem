#include <stdio.h>

int main(){
int num = 132;
int reversedNum = 0;
int remainder;
int checkNum = num;

while(num != 0){

remainder = num % 10;
reversedNum = reversedNum * 10 + remainder;
num /= 10;

};

if(checkNum == reversedNum){
    printf("Palindrome");
} else {
    printf("Not palindrome");
}

}