#include <stdio.h>


int main()
 {  
    
    int i = 5;
    int j = 7;
    int k = 3;
  if (i < j) {
    //5 < 7, so i < j, now the nested conditions will be evaluated
    if (j < k) {
        
        i = j;
    } else {
        // j > k as 7 > 3, so the value of k will be assigned to j, so j = 3
        j = k;
    }
  } else {
    // these nested conditions will be ignored as the condition i > j is not true
    if(j > k) {
        j = i;
    } else {
        i = k;
    }
  }
//final output is 5 3 3
    printf("%d %d %d\n", i, j, k);
    
}