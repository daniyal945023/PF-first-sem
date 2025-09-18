#include <stdio.h> 
int main()  
{ 
int value; 
printf("Monday = 1,\nTuesday = 2,\nWednesday = 3,\nThursday = 4,\nFriday = 5,\nSaturday = 6,\nSunday = 7\n Please enter a value in the range 1...7:\n"); 
scanf("%d", &value); 

//Translate number into its English word 

switch (value) {
    case 1:
    printf("number one represents Monday");
    break;
    case 2:
    printf("number two represents Tuesday");
    break;
    case 3:
    printf("number three represents Wednesday");
    break;
    case 4:
    printf("number four represents Thursday");
    break;
    case 5:
    printf("number five represents Friday");
    break;
    case 6:
    printf("number six represents Saturday");
    break;
    case 7:
    printf("number seven represents Sunday");
    break;

}
}