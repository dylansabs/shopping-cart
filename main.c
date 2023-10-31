#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char name[50];
    double price;
};

int main() {
    struct Item shoppingCart[MAX_ITEMS];
    int cartSize = 0;
    int choice;
    
    while (1) {
        printf("\nShopping Application\n");
        printf("1. Add an item to the cart\n");
        printf("2. View the cart\n");
        printf("3. Calculate the total cost\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (cartSize < MAX_ITEMS) {
                    printf("\nEnter item name: ");
                    scanf(" %[^\n]s", shoppingCart[cartSize].name);
                    printf("Enter item price: $");
                    scanf("%lf", &shoppingCart[cartSize].price);
                    cartSize++;
                    printf("Item added to the cart.\n");
                } else {
                    printf("\nThe cart is full. Cannot add more items.\n");
                }
                break;
            case 2:
                if (cartSize > 0) {
                    printf("\nItems in your cart:\n");
                    for (int i = 0; i < cartSize; i++) {
                        printf("%d. %s - $%.2lf\n", i + 1, shoppingCart[i].name, shoppingCart[i].price);
                    }
                } else {
                    printf("\nYour cart is empty.\n");
                }
                break;
            case 3:
                if (cartSize > 0) {
                    double totalCost = 0.0;
                    for (int i = 0; i < cartSize; i++) {
                        totalCost += shoppingCart[i].price;
                    }
                    printf("\nTotal cost of your purchases: $%.2lf\n", totalCost);
                } else {
                    printf("\nYour cart is empty.\n");
                }
                break;
            case 4:
                printf("\nExiting the program.\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    return 0;
}
