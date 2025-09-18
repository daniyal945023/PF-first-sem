
#include <stdio.h>

int main()
 {  
    
    int i = 7;
    int j = 3;
    int k = 5;
  if (i < j) {
    //7 > 3, so the condition i < j is NOT true,as a result the nested conditions will be ignored too
    if (j < k) {
        
        i = j;
    } else {
        j = k;
    }
  } else {
    // 7 > 3, so i > j, so the nested conditions will be evaluated
    if(j > k) {
        
        j = i;
    } else {
        //3 < 5 so j < k, so the value of k will be assigned to i, so i = 5
        i = k;
    }
  }
//final output is 5 3 5
    printf("%d %d %d\n", i, j, k);
    
}