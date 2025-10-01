#include <stdio.h>
#include <string.h>

int main() {
   int age;
   char gender[20];
    printf("Enter age and gender\n");
    scanf("%d", &age);
    scanf("%s", &gender);
    if(age>=18){
        if(strcmp(gender,"male")==0){
            printf("Adult Male");
        } else if(strcmp(gender,"female")==0) {
            printf("Adult Female");
        }
    } else {
        printf("Minor");
    }

    return 0;
}
