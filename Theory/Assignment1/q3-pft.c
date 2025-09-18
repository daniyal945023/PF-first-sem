#include <stdio.h>
#include <string.h>

int main(){
    int age;
    char eyesightExam[20];
    char writtenTest[20];
    char drivingTest[20];
    char medicalCertExists[20];
    char checkEligibility[20];
    printf("Answer the following questions to check eligibility for driving license\n");
    printf("Enter age\n");
    scanf("%d", &age);
    if (age >= 18) {
        printf("Did u pass your eyesight exam?\n");
        scanf("%s", &eyesightExam);
        if (strcmp(eyesightExam, "Passed") == 0) {
            printf("Did you pass your written test?\n");
            scanf("%s", &writtenTest);
            if(strcmp(writtenTest, "Passed") == 0) {
                 printf("Did you pass your driving test?\n");
                 scanf("%s", &drivingTest);
                 if(strcmp(drivingTest, "Passed") == 0) {
                      if (age > 60) {
                        printf("Do you have medical fitness certificate?\n");
                        scanf("%s", &medicalCertExists);
                        if(strcmp(medicalCertExists, "Yes") == 0) {
                            printf("You are eligible\n");
                        } else {
                            printf("You are not eligible\n");
                        }
                      } else {
                        printf("You are eligible\n");
                      }
                 } else {
                    printf("You are not eligible\n");
                 }
            } else {
                printf("You need to retake the written test\n");
            }

        } else {
            printf("You might need a prescription for glasses.\n");
        }
    } else {
        printf("You are not eligible\n");
    }

    printf("If you are not eligible, you can recheck your eligiblity\n");
    printf("Do you want to recheck?\n");

    // REPEAT THE PROCESS AGAIN
//     scanf("%s", &checkEligibility);
//     if (strcmp(checkEligibility, "Yes") == 0) {
//         printf("Enter age\n");
//     scanf("%s", &age);
//     
//     } else if (strcmp(checkEligibility, "No") == 0) {
//         printf("process ended");
//     }
// }
// .
// .
// .
// .

}