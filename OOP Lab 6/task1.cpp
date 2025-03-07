#include <iostream>
using namespace std;

class Employee {
    private:
    string name;
    float salary;

    public:
    Employee(string n, float s) {
        name = n;
        salary = s;
    }
    void displayDetails() {
        cout << "Employee name: " << name << " | Salary: " << salary;
    }
};

class Manager : public Employee {
    private:
    float bonus;

    public:
    Manager(string n, float s, float b) : Employee(n, s) {
        bonus = b;
    }
    void displayDetails() {
    Employee::displayDetails();
    cout << " | Bonus: " << bonus << endl;
    }
};

int main() {
    string name;
    float salary, bonus;

    cout << "Enter Manager's Name: ";
    cin >> name;
    cout << "Enter Salary: ";
    cin >> salary;
    cout << "Enter Bonus: ";
    cin >> bonus;

    Manager m(name, salary, bonus);
    m.displayDetails();

    return 0;
}
