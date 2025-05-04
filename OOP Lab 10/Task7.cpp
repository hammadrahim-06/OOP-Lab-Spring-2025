#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream outfile;
    outfile.open("sensor_log.txt", ios::app);

    string data[5] = {
        "Sensor 3: 90 kWH",
        "Sensor 4: 20 V",
        "Sensor 5: 65 C"
    };

    for(int i = 0;i < 5; i++) {
        outfile << data[i] << endl;
        cout << "Position: " << outfile.tellp() << endl;
    }

    outfile.close();

}