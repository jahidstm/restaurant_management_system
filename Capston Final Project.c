#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct MenuItem
{
    int id;
    char name[50];
    float price;
};

// Function to display the menu
void displayMenu(struct MenuItem menu[], int numItems)
{

    system("cls");
    system("color B0");
    printf("\t\n\n\n\t\t\t    Food Menu:\n\n");
    printf("\t-------------------------------------------------\n");
    printf("\tItem No.\tItem Name\t\tPrice\n");
    printf("\t-------------------------------------------------\n");

    for (int i = 0; i < numItems; i++)
    {
        printf("\t%d\t\t%s\t\t%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }

    printf("\t-------------------------------------------------\n");
}

// Function to place an order
void placeOrder(struct MenuItem menu[], int numItems) {
    int orderId;
    int quantity;
    float totalBill = 0;
    char choice;
    do {
        printf("\n\tEnter food id to order: ");
        scanf("%d", &orderId);

        printf("\tEnter quantity: ");
        scanf("%d", &quantity);

        int found = 0;

        for (int i = 0; i < numItems; i++) {
            if (menu[i].id == orderId) {
                totalBill += menu[i].price * quantity;
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\n\tInvalid food id!\n");
        }
        printf("\n\tDo you want to order more items? (y/n): ");
        scanf(" %c", &choice);
    }
    while (choice == 'y' || choice == 'Y');

    printf("\n\tTotal bill: %.2fTk\n", totalBill);

    printf("\n\tEnter (1) to go to the Bill Payment Section  ||  Enter (2) to go to the Main Menu");

    printf("\n\n\tEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
            {
            case 1:
                billpay(totalBill);
                break;

            default:
                return 0;
            }
}

// Function to process the payment
void processPayment(float totalBill)
{
    float amountPaid;

    printf("\n\t\t\tEnter the amount paid: ");
    scanf("%f", &amountPaid);

    // Display amount paid
    printf("\n\t\t\tAmount Paid: %.2fTk\n", amountPaid);

    if (amountPaid >= totalBill)
    {
        float change = amountPaid - totalBill;
        printf("\n\t\t\tPayment successful!    Change: %.2fTk\n", change);
    }
    else
    {
        printf("\n\t\t\tInsufficient amount paid. Payment failed.\n");
    }
}

// Function to pay the bill
void billpay(float totalBill)
{
    printf("\n\t\t\tBill Payment Section");
    printf("\n\t\t\t--------------------\n");

    printf("\n\t\t\tEnter the total bill: ");
    scanf("%f", &totalBill);

    // Apply discount for students
    char studentChoice;
    printf("\n\t\t\tAre you a student? (y/n): ");
    scanf(" %c", &studentChoice);

    if (studentChoice == 'y' || studentChoice == 'Y')
    {
        totalBill *= 0.9; // Apply 10% discount for students
        printf("\n\t\t\tCongratulations!!\tYou have got 10%% student discount.\n");
        printf("\n\t\t\tTotal bill after discount: %.2f\n", totalBill);
    }
    else
    {
        printf("\n\t\t\tTotal bill: %.2f\n", totalBill);
    }

    // Payment logic
    printf("\n\t\t\tPayment options:\n");
    printf("\t\t\t----------------\n");
    printf("\t\t\t1. Cash\n");
    printf("\t\t\t2. Credit Card\n");
    printf("\t\t\t3. Mobile Payment\n");

    int paymentChoice;
    printf("\n\t\t\tEnter your payment choice: ");
    scanf("%d", &paymentChoice);

    switch (paymentChoice)
    {
        case 1:
            processPayment(totalBill);
            break;
        case 2:
            processPayment(totalBill);
            break;
        case 3:
            processPayment(totalBill);
            break;
        default:
            printf("\n\t\t\tInvalid payment choice. Payment failed.\n");
            break;
    }

    printf("\n\t\t\tEnter (0) to go to the main Menu: ");

    int choice;
    scanf(" %c", &choice);

    if (choice == '0')
    {
        return;
    }
}


// Function to add a new menu item
void addMenuItem(struct MenuItem menu[], int numItems)
{
    printf("\n\t\t\tEnter food id: ");
    scanf("%d", &menu[numItems].id);

    printf("\n\t\t\tEnter food name: ");
    getchar();
    gets(menu[numItems].name);

    printf("\n\t\t\tEnter food price: ");
    scanf("%f", &menu[numItems].price);

    printf("\n\t\t\tMenu item added successfully!!\n");
    printf("\n\t\t\tEnter (0) to go to the main Menu: ");

    int choice;
    scanf(" %c", &choice);

    if (choice == '0')
    {
        return;
    }
}

// Function to delete a menu item
void deleteMenuItem(struct MenuItem menu[], int numItems)
{
    int idToDelete;
    printf("\n\t\t\tEnter food id to delete: ");
    scanf("%d", &idToDelete);

    int found = 0;

    for (int i = 0; i < numItems; i++)
    {
        if (menu[i].id == idToDelete)
        {
            for (int j = i; j < numItems - 1; j++)
            {
                menu[j] = menu[j + 1];
            }
            found = 1;
            break;
        }
    }
    if (found)
    {
        printf("\n\t\t\tMenu item deleted successfully!!\n");
        return numItems - 1;
    }
    else
    {
        printf("\n\t\t\tMenu item not found.\n");
        return numItems;
    }
    printf("\n\t\t\tEnter (0) to go to the main Menu: ");

    int choice;
    scanf(" %c", &choice);

    if (choice == '0')
    {
        return;
    }
}

// Function to update a menu item
void updateMenuItem(struct MenuItem menu[], int numItems)
{
    int idToUpdate;
    printf("\n\t\t\tEnter food id to update: ");
    scanf("%d", &idToUpdate);

    int found = 0;

    for (int i = 0; i < numItems; i++)
    {
        if (menu[i].id == idToUpdate)
        {
            printf("\n\t\t\tEnter new food name: ");
            scanf("%s", menu[i].name);
            printf("\n\t\t\tEnter new food price: ");
            scanf("%f", &menu[i].price);
            found = 1;
            break;
        }
    }
    if (found)
    {
        printf("\n\t\t\tMenu item updated successfully!\n");
    }
    else
    {
        printf("\n\t\t\tMenu item not found.\n");
    }
    printf("\n\t\t\tEnter (0) to go to the main Menu: ");

    int choice;
    scanf(" %c", &choice);

    if (choice == '0')
    {
        return;
    }
}


#define MAX_USERS 100

struct User
{
    char username[20];
    char password[20];
};

struct User users[MAX_USERS];
int numUsers = 0;

// Function to login
void login(char username[20], char password[20])
{
    printf("\n\t\t\tEnter username: ");
    scanf("%s", username);
    printf("\n\t\t\tEnter password: ");
    scanf("%s", password);

    int i;
    for (i = 0; i < numUsers; i++)
    {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
        {
            printf("\n\t\t\tLogin successful!\n");
            return;
        }
    }

    printf("\n\t\t\tInvalid username or password. Retry login.\n");
    login(username, password);
}

// Function to signup
void signup()
{
    if (numUsers >= MAX_USERS)
    {
        printf("\n\t\t\tMaximum number of users reached.\n");
        return;
    }

    char newUsername[20];
    char newPassword[20];

    printf("\n\t\t\tEnter a new username: ");
    scanf("%s", newUsername);
    printf("\n\t\t\tEnter a new password: ");
    scanf("%s", newPassword);

    int i;
    for (i = 0; i < numUsers; i++)
    {
        if (strcmp(newUsername, users[i].username) == 0)
        {
            printf("\n\t\t\tUsername already taken. Please choose a different username.\n");
            return;
        }
    }

    // Store the new user
    strcpy(users[numUsers].username, newUsername);
    strcpy(users[numUsers].password, newPassword);
    numUsers++;

    printf("\n\t\t\tSignup successful! You can now log in.\n");
    login(newUsername, newPassword);
}

// Function to choose login & signup
void loginMenu()
{
    int choice;
    printf("\n\t\t\t1. Login\n");
    printf("\n\t\t\t2. Sign Up\n");
    printf("\n\t\t\tEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        login(users[numUsers].username, users[numUsers].password);
        break;
    case 2:
        signup();
        break;
    default:
        printf("\n\t\t\tInvalid choice!\n");
        break;
    }
}

// Main Function
int main()
{
    system("cls");
    system("color B0");

    struct MenuItem menu[1000] =
    {
        {1, "Beef Burger", 280},
        {2, "Chicken Burger", 250},
        {3, "Family Pizza", 350},
        {4, "Sandwich", 90},
        {5, "Kacchi Biriyani", 380},
        {6, "Fried Rice", 160},
        {7, "Rice Bowl", 180},
        {8, "Chicken Wings", 120},
        {9, "Chicken swarma", 150},
        {10, "French Fries", 50},
        {11, "Grill & Naan", 420},
        {12, "Ice Cream", 100},
        {13, "Cold Coffee", 80},
        {14, "Soft Drinks", 50},
        {15, "Mineral Water", 20}
    };

    int numItems = 15;
    //float totalBill = 0;
    char username[20], password[20];
    int choice;

    while (choice != 4)
    {
        printf("\n\n\t\t\t  Welcome to CodeCraft Restaurant \n");
        printf("\t\t\t  =============================== \n\t\t\t\t\t\t\t\n");

        printf("\n\n\t\t\t    Quality food.Serves good. (^_^)\n\n                       ");
        for (int i = 0; i < 36; i++)
        {
            printf("~");
        }
        printf("\n");
        printf("                       $                                  $\n");
        printf("                       $    1. Display Menu.              $\n");
        printf("                       $                                  $\n");
        printf("                       $    2. Bill Payment.              $\n");
        printf("                       $                                  $\n");
        printf("                       $    3. Admin Section.             $\n");
        printf("                       $                                  $\n");
        printf("                       $    4. Exit.                      $");
        printf("\n");
        printf("                       $                                  $\n");
        printf("                       ");
        for (int i = 0; i < 36; i++)
        {
            printf("~");
        }

        printf("\n\n\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            //loginMenu();
            displayMenu(menu, numItems);
            placeOrder(menu, numItems);
            break;

        case 2:
            //loginMenu();
            billpay(0);
            break;

        case 3:
            loginMenu();

            printf("\n\t\t\tAdmin Section");
            printf("\n\t\t\t-------------\n");

            printf("\n\t\t\t1. Add Menu Item\n");
            printf("\n\t\t\t2. Delete Menu Item\n");
            printf("\n\t\t\t3. Update Menu Item\n");

            printf("\n\t\t\tEnter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                addMenuItem(menu, numItems);
                numItems++;
                break;

            case 2:
                deleteMenuItem(menu, numItems);
                break;

            case 3:
                updateMenuItem(menu, numItems);
                break;

            default:
                printf("\n\t\t\tInvalid choice!\n");
            }

        case 4:
            printf("\n\t\t\tExiting...\n");
            break;

        default:
            printf("\n\t\t\tInvalid choice!\n");
        }
    }

    return 0;
}
