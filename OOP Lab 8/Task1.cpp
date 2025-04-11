#include <iostream>
using namespace std;

class Humidity;

class Temperature {
    private:
    float celsiusValue;

    public:
    Temperature(float c) : celsiusValue(c) {}

    friend float calculateHeatIndex(const Temperature&, const Humidity&);
};

class Humidity {
    private:
    float relativeHumidity;

    public:
    Humidity(float h) : relativeHumidity(h) {}

    friend float calculateHeatIndex(const Temperature&, const Humidity&);
};

float calculateHeatIndex(const Temperature& tempObj, const Humidity& humidObj) {
    float tempC = tempObj.celsiusValue;
    float hum = humidObj.relativeHumidity;

    float tempF = tempC * 9.0 / 5.0 + 32.0;
    float heatIndexF = 0.5 * (tempF + 61.0 + ((tempF - 68.0) * 1.2) + (hum * 0.094));
    float heatIndexC = (heatIndexF - 32.0) * 5.0 / 9.0;
    return heatIndexC;
}

int main() {
    Temperature tObj(32.0);     
    Humidity hObj(70.0);       

    float index = calculateHeatIndex(tObj, hObj);
    cout << "Estimated comfort level (Heat Index): " << index << "(degree)C" << endl;

    return 0;
}