#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;

public:
    Account(int accNum, float b) {
        accountNumber = accNum;
        balance = b;
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << " | Balance: $" << balance;
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(int accNum, float b, float r) : Account(accNum, b) {
        interestRate = r;
    }

    void displayDetails() {
        Account :: displayDetails();
        cout << " | Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(int accNum, float b, float limit) : Account(accNum, b) {
        overdraftLimit = limit;
    }

    void displayDetails() {
        Account :: displayDetails();
        cout << " | Overdraft Limit: $" << overdraftLimit << endl;
    }
};

int main() {
    int accNum;
    float balance, interestRate, overdraftLimit;

    cout << "Enter Savings Account Details:\n";
    cout << "Account Number: ";
    cin >> accNum;
    cout << "Balance: ";
    cin >> balance;
    cout << "Interest Rate (%): ";
    cin >> interestRate;
    SavingsAccount savings(accNum, balance, interestRate);

    cout << "\nEnter Checking Account Details:\n";
    cout << "Account Number: ";
    cin >> accNum;
    cout << "Balance: ";
    cin >> balance;
    cout << "Overdraft Limit: ";
    cin >> overdraftLimit;
    CheckingAccount checking(accNum, balance, overdraftLimit);

    cout << "\nAccount Details:\n";
    savings.displayDetails();
    checking.displayDetails();

    return 0;
}