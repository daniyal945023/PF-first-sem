#include <stdio.h> 
int main()  
{ 
int value; 
printf("Please enter a value in the range 1...7:"); 
scanf("%d", &value); 
//Translate number into its English word 
if (value == 1) 
{ 
    printf("You entered a one\n");
    printf("You entered Monday");
} 
 
else if (value == 2)  
{ 
printf("You entered a two\n");
printf("You entered Tuesday"); 
} 
else if (value == 3)  
{ 
printf("You entered a three\n"); 
printf("You entered Wednesday");
} 
else if (value == 4)  
{ 
printf("You entered a four\n"); 
printf("You entered Thursday");
} 
else if (value == 5) 
{ 
printf("You entered a five\n"); 
printf("You entered Friday");
} 
else if (value == 6) 
{ 
    printf("You entered a six\n"); 
printf("You entered Saturday");
} else if (value == 7) {
    printf("You entered a seven\n"); 
printf("You entered Sunday");
} else {
printf("You entered a value out of range\n"); 
return 0; 
}
}