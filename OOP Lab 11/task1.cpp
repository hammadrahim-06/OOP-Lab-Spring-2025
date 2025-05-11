#include <iostream>
#include <cstdlib>
using namespace std;

class AgeRangeException : public exception {

    public:
        const char* what() const noexcept override {
            return "AgeRangeException - Provided age is not within a valid range (0–120)";
        }

};

bool isAgeWithinLimits(int userAge) {
    if(userAge < 0 || userAge > 120) {
        throw AgeRangeException();
    } else {
        return true;
    }
}

int main() {

    int inputAge;
    cout << "Enter age: ";
    cin >> inputAge;
    try {
        if(isAgeWithinLimits(inputAge)) {
            cout << "Age is valid" << endl;
        }
    } catch(const AgeRangeException& ex) {
        cout << ex.what() << endl;
        exit(0);
    }

}