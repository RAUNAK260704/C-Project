#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[100];
    int stock;
    float price;
};

struct Product products[MAX_PRODUCTS];
int numProducts = 0;

void addProduct() {
    if (numProducts >= MAX_PRODUCTS) {
        printf("Maximum number of products reached.\n");
        return;
    }

    struct Product newProduct;

    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);

    printf("Enter product name: ");
    scanf("%s", newProduct.name);

    printf("Enter product stock: ");
    scanf("%d", &newProduct.stock);

    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    products[numProducts] = newProduct;
    numProducts++;

    printf("Product added successfully.\n");
}

void updateStock() {
    int productId;
    int newStock;

    printf("Enter product ID: ");
    scanf("%d", &productId);

    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == productId) {
            printf("Current stock: %d\n", products[i].stock);
            printf("Enter new stock: ");
            scanf("%d", &newStock);

            products[i].stock = newStock;

            printf("Stock updated successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void removeProduct() {
    int productId;

    printf("Enter product ID: ");
    scanf("%d", &productId);

    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == productId) {
            for (int j = i; j < numProducts - 1; j++) {
                products[j] = products[j + 1];
            }

            numProducts--;

            printf("Product removed successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void generateReport() {
    printf("ID\tName\tStock\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%d\t%.2f\n", products[i].id, products[i].name, products[i].stock, products[i].price);
    }
}

void displayMenu() {
    printf("\n");
    printf("1. Add product\n");
    printf("2. Update stock\n");
    printf("3. Remove product\n");
    printf("4. Generate report\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateStock();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                generateReport();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
