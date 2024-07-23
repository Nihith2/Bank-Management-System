
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ACCOUNT CLASS
class Account {
public:
    string accountHolder;
    double balance;

    Account(const string& holder, double initialBalance)
        : accountHolder(holder), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds! | Current Balance: $" << balance << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
        }
    }

    void display() const {
        cout << "Account Holder: " << accountHolder << " | Balance: $" << balance << endl;
    }
};


//BANK CLASS
class Bank {
private:
    vector<Account> accounts;

public:
    void createAccount(const string& holder, double initialBalance) {
        accounts.push_back(Account(holder, initialBalance));
        cout << "Account created for " << holder << " with initial balance $" << initialBalance << endl;
    }

    Account* findAccount(const string& holder) {
        for (auto& account : accounts) {
            if (account.accountHolder == holder) {
                return &account;
            }
        }
        return nullptr;
    }

    void deposit(const string& holder, double amount) {
        Account* account = findAccount(holder);
        if (account) {
            account->deposit(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void withdraw(const string& holder, double amount) {
        Account* account = findAccount(holder);
        if (account) {
            account->withdraw(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void displayAccount(const string& holder) {
        Account* account = findAccount(holder);
        if (account) {
            account->display();
        } else {
            cout << "Account not found!" << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice;
    string holder;
    double amount;

    while (true) {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Account\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account holder name: ";
                cin >> holder;
                cout << "Enter initial balance: ";
                cin >> amount;
                bank.createAccount(holder, amount);
                break;
            case 2:
                cout << "Enter account holder name: ";
                cin >> holder;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bank.deposit(holder, amount);
                break;
            case 3:
                cout << "Enter account holder name: ";
                cin >> holder;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bank.withdraw(holder, amount);
                break;
            case 4:
                cout << "Enter account holder name: ";
                cin >> holder;
                bank.displayAccount(holder);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
