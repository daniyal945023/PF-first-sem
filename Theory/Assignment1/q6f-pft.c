#include <stdio.h>



int main()
 {  
    
    int i = 7;
    int j = 5;
    int k = 3;
  if (i < j) {
    //7 > 5, so the condition i < j is NOT true so the nested conditions will be ignored too
    if (j < k) {
        
        i = j;
    } else {
        j = k;
    }
  } else {
    //7 > 5, so i > j, the nested conditions will be evaluated.
    if(j > k) {
        // 5 > 3 so j > k, so the value of i will be assigned to j, so j = 7
        j = i;
    } else {
        i = k;
    }
  }
//final output is 7 7 3
    printf("%d %d %d\n", i, j, k);
    
}