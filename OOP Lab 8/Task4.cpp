#include "iostream"
using namespace std;

class Currency {
    private:
    int value;

    public:
    Currency(int val = 0) : value(val) {}

    Currency operator-() {
        return Currency(-value);
    }

    Currency operator+(Currency &c1) {
        return Currency(value + c1.value);
    }

    Currency operator-(Currency &c1) {
        return Currency(value - c1.value);
    }

    Currency& operator+=(Currency &c1) {
        value += c1.value;
        return *this;
    }

    Currency& operator-=(Currency &c1) {
        value -= c1.value;
        return *this;
    }

    friend ostream& operator<<(ostream &os, Currency &c1);
};

ostream& operator<<(ostream &os, Currency &c1) {
    os << c1.value;
    return os;
}

int main() {
    Currency c1(80), c2, c3(20);
    cout << "Initial Values:" << endl;
    cout << "C1 = " << c1 << ", C3 = " << c3 << endl;

    cout << "\nOperations:" << endl;
    c2 = c1 + c3;
    cout << "C2 = C1 + C3 -> " << c2 << endl;

    c2 = c1 - c3;
    cout << "C2 = C1 - C3 -> " << c2 << endl;

    Currency c4(10), discount(20);
    cout << "\nAdditional Values:" << endl;
    cout << "C4 = " << c4 << ", Discount = " << discount << endl;

    c2 += c4;
    cout << "C2 += C4 -> " << c2 << endl;

    c2 -= discount;
    cout << "C2 -= Discount -> " << c2 << endl;

    c1 = -c1;
    cout << "\nAfter Negation:" << endl;
    cout << "C1 (negated) = " << c1 << endl;

    return 0;
}