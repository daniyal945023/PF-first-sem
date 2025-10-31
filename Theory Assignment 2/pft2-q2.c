#include <stdio.h>
#include <string.h>

char userName[30];
int cnic;
int inventoryArr[4][3] = {
    {001, 50, 100}, {002, 10, 200}, {003, 20, 300}, {004, 8, 150}
};
int qtyPurchased;
int productId;
int j;
float bill1 = 0, bill2 = 0, bill3 = 0, bill4 = 0;
float totalBill;
float finalBill;

void customerInfo(){
       printf("Enter username and cnic\n");
       scanf("%s %d", userName, &cnic);
}

void displayInventory(){



printf("Product Code\tQuantity in Stock\tPrice per Product\n");
for(int i = 0; i < 4; i++){
    printf("\t%d\t\t\t\t \t%d\t\t\t\t \t%d\n", inventoryArr[i][0], inventoryArr[i][1], inventoryArr[i][2]);
}


}


void updateInventory(){
    
    inventoryArr[j][1] = inventoryArr[j][1] - qtyPurchased;
    
}


void addItemToCart(){
    printf("Enter items and their quantity you want to add to cart\n");
    printf("1.Shampoo\n2.Laptop\n3.Chair\n4.T-shirt\n");
    scanf("%d %d", &productId, &qtyPurchased);
    
        switch(productId){
            case 1:
            j=0;
            if(qtyPurchased <= inventoryArr[j][1]){
            updateInventory();
            bill1 = qtyPurchased * inventoryArr[j][2];
        } else {
            printf("Not enough stock\n");
        }
            break;

            case 2:
            j=1;
            if(qtyPurchased <= inventoryArr[j][1]){
            updateInventory();
            bill2 = qtyPurchased * inventoryArr[j][2];

        } else {
            printf("Not enough stock\n");
        }
            break;

            case 3:
            j=2;
            if(qtyPurchased <= inventoryArr[j][1]){
            updateInventory();
            bill3 = qtyPurchased * inventoryArr[j][2];
        } else {
            printf("Not enough stock\n");
        }
            break;

            case 4:
            j=3;
            if(qtyPurchased <= inventoryArr[j][1]){
            updateInventory();
            bill4 = qtyPurchased * inventoryArr[j][2];
        } else {
            printf("Not enough stock\n");
        }
            break;

            default:
            printf("Product does not exist\n");
            break;
        }


}



void displayTotalBill(){
totalBill = bill1 + bill2 + bill3 + bill4;
printf("Total Bill: %.2f\n", totalBill);
printf("Do you have any promocode vouchers?\nWe are offering  a promocode of Eid2025\n");
printf("Do you have the promocode voucher?(Y/N)\n");
char choice;
scanf(" %c", &choice);

switch(choice){
    case 'Y':
    finalBill = totalBill - (totalBill * 0.25);
    break;

    case 'N':
    finalBill = totalBill;
    break;

    default:
    printf("Invalid option\n");
}

printf("Total Bill: %.2f", finalBill);


}


void showInvoice(){
if(finalBill == totalBill){
    printf("userName: %s\nFinal Bill: %.2f\nDiscount: 0%%", userName, finalBill);
} else {
    printf("userName: %s\nFinal Bill: %.2f\nDiscount: 25%%", userName, finalBill);
}

}


void exitSystem(){
    printf("System exited\n");
}


int main(){

int choice;

do{
printf("Choose the following options:\n1.Customer Information\n2.Display Inventory\n3.Update Inventory\n4.Add Item to Cart\n5.Display Total Bill\n6.Show Invoice\n7.Exit the System\n");
scanf("%d", &choice);

switch(choice){
    case 1:
    customerInfo();
    break;

    case 2:
    displayInventory();
    break;

    case 3:
    updateInventory();
    break;

    case 4:
    addItemToCart();
    break;

    case 5:
    displayTotalBill();
    break;

    case 6:
    showInvoice();
    break;

    case 7:
    exitSystem();
    break;

    default:
    printf("Invalid option");
    break;


}} while(choice != 7);



    return 0;
}