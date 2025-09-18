#include <stdio.h>

int main()
 {  
    
    int i = 3;
    int j = 5;
    int k = 7;
  if (i < j) {
    // 3 < 5, now the conditions inside this nested if will be evaluated
    if (j < k) {
        // 5 < 7, so j < k condition is true, so 5 will be assigned to i as well
        i = j;
    } else {
        j = k;
    }
  } else {
    // these conditions are not true so they will be ignored.
    if(j > k) {
        j = i;
    } else {
        i = k;
    }
  }

    printf("%d %d %d\n", i, j, k);
    // The final output is 5 5 7
}