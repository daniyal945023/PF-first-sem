#include <stdio.h>

int main(){
    int attendance;
    int internalMarks;
    printf("To check whether you can enter final exam or not,type your attendance and internal marks\n");
    printf("Enter Attendance\n");
    scanf("%d", &attendance);
    printf("Enter Internal Marks\n");
    scanf("%d", &internalMarks);
    printf("Attendance is %d%% and internal marks are %d\n", attendance, internalMarks);
    if(attendance >= 75 && internalMarks >= 40) {
        printf("You can sit in final exam");
    } else {
        printf("You cannot sit in final exam");
    }
}