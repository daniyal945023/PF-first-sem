#include <stdio.h>
#include <string.h>

int isbns[100];
char titles[100][50];
float prices[100];
int quantities[100];
int bookCount = 0;



void addNewBook(){
    int isbn;
    char title[50];
    float price;
    int quantity;
    int i, duplicate = 0;

     if (bookCount >= 100) {
        printf("Inventory full,Cannot add more books.\n");
        return;
    }


    
    printf("Enter details of new book\n");
    scanf("%d", &isbn);
getchar(); 
printf("Enter Title: ");
fgets(title, sizeof(title), stdin);
title[strcspn(title, "\n")] = '\0'; 
printf("Enter Price and Quantity: ");
scanf("%f %d", &price, &quantity);
    
for (i = 0; i < bookCount; i++) {
        if (isbns[i] == isbn) {
            printf("Error: A book with ISBN %d already exists.\n", isbn);
            duplicate = 1;
            break;
        }
    }

    if (duplicate == 1) {
        return;
    }


     isbns[bookCount] = isbn;
    strcpy(titles[bookCount], title);
    prices[bookCount] = price;
    quantities[bookCount] = quantity;

    bookCount++;

    printf("Book added successfully!\n");

    
    
}


void processaSale(){
    printf("Enter an ISBN No. and number of copies sold\n");
    int isbn, quantitySold;
     int found = 0;
    int i;
    scanf("%d %d", &isbn, &quantitySold);

    for(i = 0; i < bookCount; i++){
    if(isbns[i] == isbn){
        found = 1;
        if(quantitySold <= quantities[i]){
            quantities[i] = quantities[i] - quantitySold;
            printf("Sale processed successfully. Remaining stock: %d\n", quantities[i]);
        } else {
            printf("Error: Not enough stock. Only %d copies available.\n", quantities[i]);
        }
        break;
    }
}
        if (found == 0){
            printf("Error: Book with ISBN %d not found.\n", isbn);
    }
}
    



void generateLowStockReport(){
    int lowStockFound = 0;

for(int i = 0; i < bookCount; i++){
    if(quantities[i] < 5){
        printf("ISBN: %d\nTitle: %s\nPrice: %.2f\nQuantity: %d\n", isbns[i], titles[i], prices[i], quantities[i]);
        lowStockFound = 1;
    } 
}

if (lowStockFound == 0) {
        printf("No low stock items found.\n");
    }

}




int main(){


int choice;
 do {
        printf("\n=== Bookstore Inventory Menu ===\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewBook();
                break;
            case 2:
                processaSale();
                break;
            case 3:
                generateLowStockReport();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}