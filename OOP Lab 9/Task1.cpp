#include <iostream>
using namespace std;

class Vehicle {
    protected:
    string model;
    double rate;

    public:
    Vehicle(string model, double rate) : model(model), rate(rate) {}
    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;

};

class Car : public Vehicle {
    public:
    Car(string model, double rate) : Vehicle(model, rate) {}
    double getDailyRate() override {
        return rate;
    }

    void displayDetails() override {
        cout << "*** Car Details ***\n";
        cout << "Model Name: " << model << " | Rate: " << rate << endl;
    }
};

class Bike : public Vehicle {
    public:
    Bike(string model, double rate) : Vehicle(model, rate) {}
    double getDailyRate() override {
        return rate;
    }

    void displayDetails() override {
        cout << "*** Bike Details ***\n";
        cout << "Model Name: " << model << " | Rate: " << rate << endl;
    }
};

int main() {
    Vehicle* v1 = new Car("Hyundai Sonata N-Line", 100.0);
    Vehicle* v2 = new Bike("Kawasaki Ninja H2", 50.0);
    v1->displayDetails();
    cout << "Daily Rate: " << v1->getDailyRate() << endl << endl;
    v2->displayDetails();
    cout << "Daily Rate: " << v2->getDailyRate() << endl;
    delete v1;
    delete v2;

    return 0;
}