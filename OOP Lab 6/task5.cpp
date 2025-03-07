#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;

public:
    Device(int id, bool stat) {
        deviceID = id;
        status = stat;
    }

    void displayDetails() {
        cout << "Device ID: " << deviceID << " | Status: " << (status ? "Active" : "Inactive");
    }
};

class SmartPhone : public Device {
protected:
    float screenSize;

public:
    SmartPhone(int id, bool stat, float ss) : Device(id, stat) {
        screenSize = ss;
    }

    void displayDetails() {
        Device :: displayDetails();
        cout << " | Display Size: " << screenSize << " inches";
    }
};

class SmartWatch : virtual public Device {
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool stat, bool hr) : Device(id, stat) {
        heartRateMonitor = hr;
    }

    void displayDetails() {
        Device :: displayDetails();
        cout << " | HR Monitor: " << (heartRateMonitor ? "Enabled" : "Disabled");
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;

public:
    SmartWearable(int id, bool stat, float ss, bool hr, int steps) : Device(id, stat), SmartPhone(id, stat, ss), SmartWatch(id, stat, hr) {
        stepCounter = steps;
    }

    void displayDetails() {
        SmartPhone::displayDetails();
        cout << " | HR Monitor: " << (heartRateMonitor ? "Yes" : "No");
        cout << " | Steps Tracked: " << stepCounter << endl;
    }
};

int main() {
    int deviceID, stepCounter;
    bool status, heartRateMonitor;
    float screenSize;

    cout << "Enter Smart Wearable Specifications:\n";
    cout << "Enter Device ID: ";
    cin >> deviceID;
    cout << "Is the device active? (1 for Yes, 0 for No): ";
    cin >> status;
    cout << "Enter Screen Size (inches): ";
    cin >> screenSize;
    cout << "Does it have a heart rate monitor? (1 for Yes, 0 for No): ";
    cin >> heartRateMonitor;
    cout << "Enter Step Counter Value: ";
    cin >> stepCounter;

    SmartWearable gadget(deviceID, status, screenSize, heartRateMonitor, stepCounter);

    cout << "\nSmart Wearable Details:\n";
    gadget.displayDetails();

    return 0;
}