#include <iostream>
using namespace std;

class Vehicle {
    private:
    string brand;
    int speed;

    public:
    Vehicle(string b, int s) {
        brand = b;
        speed = s;
    }
    void displayDetails() {
        cout << "Brand name: " << brand << " | (Top)speed: " << speed;
    }
};

class Car : public Vehicle {
    private:
    int seats;

    public:
    Car(string b, int s, int seat) : Vehicle(b, s) {
        seats = seat;
    }
    void displayDetails() {
        Vehicle :: displayDetails();
        cout << " | Number of seats: " << seats;
    }
    
};

class ElectricCar : public Car {
    private:
    int batteryLife;

    public :
    ElectricCar(string b, int s, int seat, int bl) : Car(b, s, seat) {
        batteryLife = bl;
    }
    void displayDetails() {
        Car :: displayDetails();
        cout << " | Battery Life: " << batteryLife;
    }
};

int main() {
    string brand;
    int speed, seats, batteryLife;

    cout << "Enter Brand Name: ";
    cin >> brand;
    cout << "Enter Speed: ";
    cin >> speed;
    cout << "Enter Number of Seats: ";
    cin >> seats;
    cout << "Enter Battery Life (in hours): ";
    cin >> batteryLife;

    ElectricCar eCar(brand, speed, seats, batteryLife);
    eCar.displayDetails();

    return 0;
}