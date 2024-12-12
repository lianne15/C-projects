/*
Solution Plan:
1. Define a structure `Account` to store bank account details (account number, holder name, balance).
2. Implement functions to:
   - Create a new account.
   - Display account details.
   - Deposit money.
   - Withdraw money.
3. Use a menu-driven interface for user interaction.
*/

#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Define the structure for storing account details
typedef struct {
    int accountNumber;
    char holderName[100];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS]; // Array to store accounts
int accountCount = 0;          // Tracks the number of accounts

// Function to create a new account
void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached!\n");
        return;
    }

    Account newAccount;

    printf("Enter Account Number: ");
    scanf("%d", &newAccount.accountNumber);
    getchar(); // Consume newline character

    printf("Enter Account Holder Name: ");
    fgets(newAccount.holderName, sizeof(newAccount.holderName), stdin);
    newAccount.holderName[strcspn(newAccount.holderName, "\n")] = 0; // Remove newline character

    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &newAccount.balance);

    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n\n");
}

// Function to display account details
void displayAccounts() {
    if (accountCount == 0) {
        printf("No accounts available!\n\n");
        return;
    }

    printf("\n--- Account Details ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Holder Name: %s\n", accounts[i].holderName);
        printf("Balance: %.2f\n\n", accounts[i].balance);
    }
}

// Function to deposit money
void depositMoney() {
    int accountNumber;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Amount deposited successfully! New Balance: %.2f\n\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n\n");
}

// Function to withdraw money
void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance!\n\n");
            } else {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully! New Balance: %.2f\n\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found!\n\n");
}

// Main function
int main() {
    int choice;

    do {
        // Display the menu
        printf("\n--- Bank Account Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
