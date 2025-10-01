#include <stdio.h>

int main(){
  int n = 10;
    int i;
    int a = 0, b = 1;
    printf("%d\n%d\n", a,b);
    int next;
    
    

    for(i = 3; i <= n; i++) {
    next = a + b; 
    printf("%d\n", next); 
        a = b; 
        b = next;
    }
 

    return 0;
}