#include <iostream>
using namespace std;

class SmartDevice {
    public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool getStatus() = 0;
};

class LightBulb : public SmartDevice {
    private:
    bool isOn;
    int brightness;

    public:
    LightBulb(bool isOn, int brightness) : isOn(isOn), brightness(brightness) {}
    void turnOn() override {
        isOn = true;
    }
    void turnOff() override {
        isOn = false;
    } 
    bool getStatus() override {
        return isOn;
    }
};

class Thermostat : public SmartDevice {
    private:
    bool isOn;
    double temperature;

    public:
    Thermostat(bool isOn = false, double temperature = 22.0) : isOn(isOn), temperature(temperature) {}
    void turnOn() override {
        isOn = true;
    }
    void turnOff() override {
        isOn = false;
    } 
    bool getStatus() override {
        return isOn;
    }
};

int main() {
    LightBulb bulb(false, 75);
    cout << "LightBulb initial status: " << (bulb.getStatus() ? "On" : "Off") << endl;

    bulb.turnOn();
    cout << "LightBulb status after turning on: " << (bulb.getStatus() ? "On" : "Off") << endl;

    bulb.turnOff();
    cout << "LightBulb status after turning off: " << (bulb.getStatus() ? "On" : "Off") << endl;

    Thermostat thermostat;
    cout << "Thermostat initial status: " << (thermostat.getStatus() ? "On" : "Off") << endl;

    thermostat.turnOn();
    cout << "Thermostat status after turning on: " << (thermostat.getStatus() ? "On" : "Off") << endl;

    thermostat.turnOff();
    cout << "Thermostat status after turning off: " << (thermostat.getStatus() ? "On" : "Off") << endl;

    return 0;
}