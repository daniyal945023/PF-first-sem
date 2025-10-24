#include <stdio.h>

int main(){
int total;
float avg;
int sum;
    int marks[5][3] = {
        {80,75,90},
        {60,70,65},
        {78,82,88},
        {92,85,89},
        {55,60,58}
    };

    for(int i = 0; i < 5; i++){
        total = 0;
        for(int j = 0; j < 3; j++){
          total = total + marks[i][j]; // 0+marks[0][0], marks[0][0] + [0][1] =amt1, amt1 + [0][2] = amt2 then exit j loop, then print that total, then i++, i = 1; enter j loop, total should start with 0 again but this time 0 + [1][0], then [1][0] + [1][1] = amt1, amt1 + [1][2] = amt2, amt2 + [1][3] then j loop exits, then total marks r pritned, then i++, i = 2 and so on
        }
        printf("total Marks for student %d are %d\n", i+1, total);
    }

        for(int i = 0; i < 3;i++){
            sum = 0;
            for(int j = 0; j < 5; j++){
                    sum = sum + marks[j][i];
            }
            avg = sum/5.0;
            printf("The avg of subject %d is %.2f\n", i+1, avg);
        }

    






    return 0;
}