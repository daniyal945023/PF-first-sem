#include <stdio.h>

int main(){
int zerocount = 0;
int onecount = 0;
int twocount = 0;
int threecount = 0;
int fourcount = 0;
int fivecount = 0;
int sixcount = 0;
int sevencount = 0;
int eightcount = 0;
int ninecount = 0;
int num = 0;

while (num >= 0 && num <= 9)
{
    printf("Enter a number\n");
    scanf("%d", &num);
    if (num == 0)
    zerocount += 1;
 else if (num == 1)
   onecount += 1;
 else if (num == 2)
    twocount += 1;
 else if (num == 3)
    threecount += 1;
 else if (num == 4)
    fourcount += 1;
 else if (num == 5)
    fivecount += 1;
 else if (num == 6)
     sixcount += 1;
 else if (num == 7)
     sevencount += 1;
 else if (num == 8)
      eightcount += 1;
 else if (num == 9)
      ninecount += 1;

}

printf("Numbers:0,1,2,3,4,5,6,7,8,9\n");
printf("No of occurences: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", zerocount, onecount, twocount, threecount, fourcount, fivecount, sixcount, sevencount, eightcount, ninecount);


}