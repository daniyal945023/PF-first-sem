#include <stdio.h>


    

void update(int grid[4][4], int rows, int cols){
    int r,c,flag,val;

 printf("Enter sector coordinates(row,col): ");
    scanf("%d %d", &r, &c);

    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        printf("Invalid coordinates.\n");
        return;
    }

printf("Which flag to update?\n");
    printf("1. Power (bit 0)\n2. Overload (bit 1)\n3. Maintenance (bit 2)\n");
    scanf("%d", &flag);

    printf("Enter 1 to set, 0 to clear: ");
    scanf("%d", &val);

    if (val == 1) {
        grid[r][c] = grid[r][c] | (1 << (flag - 1));     // set bit
    } else {
        grid[r][c] = grid[r][c] & ~(1 << (flag - 1));    // clear bit
    }

    printf("Sector (%d, %d) updated successfully! New value: %d\n", r, c, grid[r][c]);
}




    


void query(int grid[4][4], int rows, int cols) {
    int r, c;
    printf("Enter sector coordinates (row col): ");
    scanf("%d %d", &r, &c);

    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        printf("Invalid coordinates.\n");
        return;
    }

    int value = grid[r][c];

    printf("\nStatus for Sector (%d, %d):\n", r, c);
    if (value & (1 << 0))
        printf("Power: ON\n");
    else
        printf("Power: OFF\n");

    if (value & (1 << 1))
        printf("Overload: YES\n");
    else
        printf("Overload: NO\n");

    if (value & (1 << 2))
        printf("Maintenance Required: YES\n");
    else
        printf("Maintenance Required: NO\n");
}


void diagnostic(int grid[4][4], int rows, int cols) {
    int overloadCount = 0;
    int maintenanceCount = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] & (1 << 1))
                overloadCount++;
            if (grid[i][j] & (1 << 2))  
                maintenanceCount++;
        }
    }

     printf("\nSystem Diagnostic Report:\n");
    printf("Total Overloaded Sectors: %d\n", overloadCount);
    printf("Total Maintenance Required: %d\n", maintenanceCount);
}






int main(){
     int grid[4][4] = {
        {1, 3, 0, 5},
        {2, 7, 4, 0},
        {3, 1, 6, 2},
        {0, 4, 1, 7}
    };
    
int choice;
    

do{
    printf("1.Update\n2.Query\n3.Diagnostic\n4.Exit\nEnter a number\n");
    
    scanf("%d", &choice);

    switch(choice){
       case 1:
       update(grid, 4, 4);
       break;

       case 2:
       query(grid, 4, 4);
       break;

       case 3:
       diagnostic(grid, 4, 4);
       break;

       case 4:
       printf("Exiting System\n");
       break;

       default:
       printf("Invalid choice, try again\n");

    }
} while(choice != 4);

    return 0;
}