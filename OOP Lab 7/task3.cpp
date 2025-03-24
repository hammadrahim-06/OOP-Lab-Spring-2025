#include <iostream>
using namespace std;

class Currency {
    protected:
    double value;
    string currencyCode;
    string currencySymbol;
    double rateToBase;  

    public:
    Currency(double val, string code, string symbol, double rate): value(val), currencyCode(code), currencySymbol(symbol), rateToBase(rate) {}

    virtual double convertToBase() {
        return value * rateToBase;
    }

    virtual double exchange(Currency& targetCurrency) {
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency.rateToBase;
    }

    virtual void showCurrency() {
        cout << currencySymbol << " " << value << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency {
    public:
    Dollar(double val) : Currency(val, "USD", "$", 1.0) {}
    void showCurrency() override {
        cout << "$" << value << " (USD)" << endl;
    }
};

class Euro : public Currency {
    public:
    Euro(double val) : Currency(val, "EUR", "€", 1.12) {} 

    void showCurrency() override {
        cout << value << "eur (EUR)" << endl;
    }
};

class Rupee : public Currency {
    public:
    Rupee(double val) : Currency(val, "PKR", "₨", 0.0062) {}
    void showCurrency() override {
        cout << value << "Rs (PKR)" << endl;
    }
};

int main() {
    Dollar usd(150);
    Euro eur(75);
    Rupee pkr(8000);

    cout << "=== Account Balance Details ===\n";
    usd.showCurrency();
    eur.showCurrency();
    pkr.showCurrency();

    cout << "\n=== Currency Exchange Conversions ===\n";
    cout << "150 USD to EUR: " << usd.exchange(eur) << " EUR\n";
    cout << "75 EUR to PKR: " << eur.exchange(pkr) << " PKR\n";
    cout << "8000 PKR to USD: " << pkr.exchange(usd) << " USD\n";

    return 0;
}