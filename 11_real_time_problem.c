#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Account {
    int accountNumber;
    char holderName[50];
    float balance;
};

int createAccount(struct Account accounts[], int numAccounts, int accountNumber, const char* holderName, float balance) {
    if (numAccounts < MAX_ACCOUNTS) {
        accounts[numAccounts].accountNumber = accountNumber;
        strcpy(accounts[numAccounts].holderName, holderName);
        accounts[numAccounts].balance = balance;
        return numAccounts + 1; // Increment number of accounts
    } else {
        printf("Maximum number of accounts reached\n");
        return numAccounts; // Return current number of accounts without incrementing
    }
}

void deposit(struct Account accounts[], int numAccounts, int accountNumber, float amount) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Deposited %.2f into account %d\n", amount, accountNumber);
            return;
        }
    }
    printf("Invalid account number\n");
}

void withdraw(struct Account accounts[], int numAccounts, int accountNumber, float amount) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawn %.2f from account %d\n", amount, accountNumber);
            } else {
                printf("Insufficient balance in account %d\n", accountNumber);
            }
            return;
        }
    }
    printf("Invalid account number\n");
}

void checkBalance(struct Account accounts[], int numAccounts, int accountNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account %d Balance: %.2f\n", accountNumber, accounts[i].balance);
            return;
        }
    }
    printf("Invalid account number\n");
}

int main() {
    struct Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;
    int accountNumber;
    float amount;

    do {
        printf("\nBanking System Menu\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numAccounts < MAX_ACCOUNTS) {
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    printf("Enter holder name: ");
                    char holderName[50];
                    scanf("%s", holderName);
                    printf("Enter initial balance: ");
                    scanf("%f", &amount);
                    numAccounts = createAccount(accounts, numAccounts, accountNumber, holderName, amount);
                } else {
                    printf("Maximum number of accounts reached\n");
                }
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                deposit(accounts, numAccounts, accountNumber, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(accounts, numAccounts, accountNumber, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                checkBalance(accounts, numAccounts, accountNumber);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
