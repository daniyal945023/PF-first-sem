#include <stdio.h>
#include <string.h>


struct Employee{
    int id;
    char name[20];
    char designation[20];
    int salary;
};


void inputEmployees(struct Employee e[], int n){
for(int i = 0; i < n; i++){
    printf("enter id\n");
    scanf("%d", &e[i].id);
    printf("enter name\n");
    scanf("%s", e[i].name);
    printf("enter designation\n");
    scanf("%s", e[i].designation);
    printf("enter salary\n");
    scanf("%d", &e[i].salary);

    
}

}




void displayEmployees(struct Employee e[], int n){

    printf("ID\t Name\t Designation\t Salary\n");
    for(int i = 0; i < n; i++){
        printf("%d\t %s\t %s\t %d\n", e[i].id,e[i].name,e[i].designation,e[i].salary);
    }
    
}

void findHighestSalary(struct Employee e[], int n){
    int maxIndex =0;
    //max = e[0].salary
    //if e[0].salary < e[i].salary
    //max = e[i].salary
    for(int i =0; i < n; i++){
        if(e[maxIndex].salary < e[i].salary){
            maxIndex = i;
            
        }
    }
printf("\nemployee with highest salary\n");
            printf("%d\t %s\t %s\t %d\n", e[maxIndex].id,e[maxIndex].name,e[maxIndex].designation,e[maxIndex].salary);

}



void searchEmployee(struct Employee e[], int n){
printf("Do u want to search by ID or name? choose I or N\n");
char choice;
scanf(" %c", &choice);
switch(choice){

    case 'I': {
    printf("enter id\n");
    int id;
    scanf("%d", &id);
    int found=0;
    for(int i =0; i < n; i++){
        if(id == e[i].id){
            printf("match found\n");
           printf("%d\t %s\t %s\t %d\n", e[i].id,e[i].name,e[i].designation,e[i].salary);
           found = 1;
           break;
        } 
            
    }

    if(!found){
        printf("match not found");
    }
    break;
}
    case 'N': {
    printf("enter name\n");
    char employeeName[20];
    scanf("%s", employeeName);
    int found = 0;
    for(int i =0; i < n; i++){
        if(strcmp(employeeName, e[i].name)==0){
            printf("match found\n");
            printf("%d\t %s\t %s\t %d\n", e[i].id,e[i].name,e[i].designation,e[i].salary);
            found =1;
            break;
        }
    }

    if(!found){
        printf("match not found\n");
    }
    break;
}
    default:
    printf("invalid choice\n");
    break;


}

}



//for 10% bonus, we will create this function:
void giveBonus(struct Employee e[], int n, int threshold) {
    for(int i = 0; i < n; i++) {
        if(e[i].salary < threshold) {
            e[i].salary += e[i].salary * 0.10;  
        }
    }
}






int main(){

 int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee e[n];
    inputEmployees(e, n);

    int choice;
    do {
        printf("\nHR Menu:\n1. Display All\n2. Highest Salary\n3. Search Employee\n4. Give Bonus\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: displayEmployees(e, n); break;
            case 2: findHighestSalary(e, n); break;
            case 3: searchEmployee(e, n); break;
            case 4: giveBonus(e, n, 50000); printf("Bonus applied.\n"); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 5);

    return 0;




    return 0;
}