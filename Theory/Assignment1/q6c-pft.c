#include <stdio.h>


int main()
 {  
    
    int i = 5;
    int j = 3;
    int k = 7;
  if (i < j) {
    // i > j, 5 > 3, so the nested conditions will be ignored
    if (j < k) {
        
        i = j;
    } else {
        j = k;
    }
  } else {
    // i > j, 5 > 3 now the nested conditions will be evaluated
    if(j > k) {
        j = i;
    } else {
        // 3 < 7, so j < k so the value of k will be assigned to i, so i = 7
        i = k;
    }
  }
//final output is 7 3 7
    printf("%d %d %d\n", i, j, k);
    
}