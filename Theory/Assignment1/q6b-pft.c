#include <stdio.h>

int main()
 {  
    
    int i = 3;
    int j = 7;
    int k = 5;
  if (i < j) {
    // 3 < 7, so i < j, the conditions inside this conditional will be evaluated
    if (j < k) {
        // 7 > 5, so j > k, so the value of k, which is 5 will be assigned to j: j = 5
        i = j;
    } else {
        j = k;
    }
  } else {
    // the nested conditions will be ignored as this condition(i > j) is not true
    if(j > k) {
        j = i;
    } else {
        i = k;
    }
  }
//final output is 3 5 5
    printf("%d %d %d\n", i, j, k);
    
}