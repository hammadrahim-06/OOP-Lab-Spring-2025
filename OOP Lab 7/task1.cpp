#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNum, string holderName, string type, float initialBalance)
        : accountNumber(accNum), accountHolderName(holderName), accountType(type), balance(initialBalance) {}

    void deposit(float amount) {
        balance += amount;
        cout << "Deposited: $" << amount << ". New Balance: $" << balance << endl;
    }

    virtual void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: $" << amount << ". Remaining Balance: $" << balance << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Calculating Interest..." << endl;
    }

    virtual void printStatement() {
        cout << "Printing detailed transaction histories..." << endl;
    }

    void getAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class SavingsAccount : public Account {
    private:
    float interestRate;
    float minimumBalance;

    public:
    SavingsAccount(int accNum, string holderName, float initialBalance, float interest, float minBal) : Account(accNum, holderName, "Savings", initialBalance), interestRate(interest), minimumBalance(minBal) {}

    void calculateInterest() override {
        float interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest added: $" << interest << ". New Balance: $" << balance << endl;
    }

    void printStatement() override {
        cout << "Printing detailed transaction histories for Savings Account..." << endl;
    }

    void withdraw(float amount) override {
        if (amount > balance) {
            cout << "Insufficient Balance!" << endl;
        } else if ((balance - amount) < minimumBalance) {
            cout << "Cannot withdraw. Minimum balance requirement of $" << minimumBalance << " must be maintained!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: $" << amount << ". Remaining Balance: $" << balance << endl;
        }
    }
};

class CheckingAccount : public Account {
    private:
    float transactionFee;

    public:
    CheckingAccount(int accNum, string holderName, float initialBalance, float fee): Account(accNum, holderName, "Checking", initialBalance), transactionFee(fee) {}

    void withdraw(float amount) override {
        float totalAmount = amount + transactionFee;
        if (totalAmount > balance) {
            cout << "Insufficient Balance! Cannot withdraw $" << amount << " with a transaction fee of $" << transactionFee << endl;
        } else {
            balance -= totalAmount;
            cout << "Withdrew: $" << amount << " (Fee: $" << transactionFee << "). Remaining Balance: $" << balance << endl;
        }
    }

    void printStatement() override {
        cout << "Printing detailed transaction histories for Checking Account..." << endl;
    }
};

class FixedDepositAccount : public Account {
    private:
    float fixedInterestRate;
    int maturityDays;  

    public:
    FixedDepositAccount(int accNum, string holderName, float initialBalance, float interestRate, int days) : Account(accNum, holderName, "Fixed Deposit", initialBalance), fixedInterestRate(interestRate), maturityDays(days) {}

    void calculateInterest() override {
        if (maturityDays <= 0) {
            float interest = balance * (fixedInterestRate / 100);
            balance += interest;
            cout << "Maturity reached! Interest added: $" << interest << ". New Balance: $" << balance << endl;
        } else {
            cout << "Interest will be added after " << maturityDays << " days." << endl;
        }
    }

    void withdraw(float amount) override {
        if (maturityDays > 0) {
            cout << "Cannot withdraw before maturity! " << maturityDays << " days remaining." << endl;
        } else {
            cout << "Withdrawing full balance of $" << balance << " as deposit has matured." << endl;
            balance = 0;
        }
    }

    void decreaseMaturityDays(int days) {
        maturityDays -= days;
        if (maturityDays < 0) maturityDays = 0;
    }

    void printStatement() override {
        cout << "Fixed Deposit Account Statement: Interest Rate: " << fixedInterestRate  << "%, Days Until Maturity: " << maturityDays << endl;
    }
};

int main() {
    SavingsAccount savings(2001, "Ahmed Khan", 3000.0, 5.0, 1000.0);
    CheckingAccount checking(2002, "Fatima Ali", 2500.0, 15.0);
    FixedDepositAccount fixedDeposit(2003, "Bilal Raza", 7000.0, 6.0, 40);

    savings.getAccountInfo();
    savings.deposit(1000);
    savings.withdraw(2500);
    savings.calculateInterest();
    savings.printStatement();
    cout << "\n";

    checking.getAccountInfo();
    checking.deposit(500);
    checking.withdraw(1000);
    checking.printStatement();
    cout << "\n";

    fixedDeposit.getAccountInfo();
    fixedDeposit.withdraw(2000);
    fixedDeposit.calculateInterest();
    fixedDeposit.printStatement();

    cout << "\nSimulating 40 days passing...\n";
    fixedDeposit.decreaseMaturityDays(40);
    fixedDeposit.calculateInterest();
    fixedDeposit.withdraw(7000);
    fixedDeposit.printStatement();

    return 0;
}