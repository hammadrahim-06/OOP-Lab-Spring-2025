#include "iostream"
using namespace std;

class Fraction {
    private:
    int numerator;
    int denominator;

    public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {}

    Fraction operator+(Fraction &f1) {
        if (denominator == 0 || f1.denominator == 0) {
            cout << "MATH ERROR: Invalid denominator!" << endl;
            return 0;
        }
        else if (denominator == f1.denominator) {
            return Fraction(numerator + f1.numerator, denominator);
        }
        else {
            numerator *= f1.denominator;
            f1.numerator *= denominator;
            return Fraction(numerator + f1.numerator, denominator * f1.denominator);
        }
    }

    Fraction operator-(Fraction &f1) {
        if (denominator == 0 || f1.denominator == 0) {
            cout << "MATH ERROR: Invalid denominator!" << endl;
            return 0;
        }
        else if (denominator == f1.denominator) {
            return Fraction(numerator - f1.numerator, denominator);
        }
        else {
            numerator *= f1.denominator;
            f1.numerator *= denominator;
            return Fraction(numerator - f1.numerator, denominator * f1.denominator);
        }
    }

    Fraction operator*(Fraction &f) {
        if (denominator == 0 || f.denominator == 0) {
            cout << "MATH ERROR: Invalid denominator!" << endl;
            return 0;
        }
        return Fraction(numerator * f.numerator, denominator * f.denominator);
    }

    Fraction operator/(Fraction &f) {
        if (denominator == 0 || f.denominator == 0) {
            cout << "MATH ERROR: Invalid denominator!" << endl;
            return 0;
        }
        return Fraction(numerator / f.numerator, denominator / f.denominator);
    }

    friend ostream& operator<<(ostream &os, Fraction &f);
};

ostream& operator<<(ostream &os, Fraction &f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}

int main() {
    Fraction f1(10, 6), d1(5, 3), f2, f3, f4, f5;

    cout << "Initial Fractions:" << endl;
    cout << "F1 = " << f1 << " | D1 = " << d1 << endl;

    f4 = f1 * d1;
    f5 = f1 / d1;
    f2 = f1 + d1;
    f3 = d1 - f1;

    cout << "\n[ Addition ]" << endl;
    cout << "F1 + D1 = " << f2 << endl;

    cout << "\n[ Subtraction ]" << endl;
    cout << "D1 - F1 = " << f3 << endl;

    cout << "\n[ Multiplication ]" << endl;
    cout << "F1 * D1 = " << f4 << endl;

    cout << "\n[ Division ]" << endl;
    cout << "F1 / D1 = " << f5 << endl;

    return 0;
}