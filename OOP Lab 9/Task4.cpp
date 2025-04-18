#include <iostream>
using namespace std;

class PaymentMethod {
    public:
    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod {
    private:
    string cardNumber;

    public:
    CreditCard(string num) : cardNumber(num) {}
    void processPayment(double amount) override {
        cout << "Validating card number: " << cardNumber << endl;
        if (cardNumber.length() == 16) {
            cout << "Payment of Rs " << amount << " processed with Credit Card." << endl;
        } 
        else {
            cout << "Invalid card number. Payment failed." << endl;
        }
    }

};

class DigitalWallet : public PaymentMethod {
    private:
    double balance;

    public:
    DigitalWallet(double b) : balance(b) {}
    void processPayment(double amount) override {
        cout << "Processing payment with Digital Wallet..." << endl;
        if (balance >= amount) {
            balance -= amount;
            cout << "Payment of Rsv" << amount << " successful. Remaining balance: Rs " << balance << endl;
        }
         else {
            cout << "Insufficient balance. Payment failed." << endl;
        }
    }
};

int main() {
    PaymentMethod* method1 = new CreditCard("1234567890123456");
    method1->processPayment(150.75);

    PaymentMethod* method2 = new CreditCard("1111");
    method2->processPayment(99.99);

    PaymentMethod* method3 = new DigitalWallet(200.00);
    method3->processPayment(50.00);
    method3->processPayment(160.00);

    PaymentMethod* method4 = new DigitalWallet(30.00);
    method4->processPayment(60.00);

    delete method1;
    delete method2;
    delete method3;
    delete method4;

    return 0;
}