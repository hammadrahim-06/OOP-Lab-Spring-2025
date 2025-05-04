#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>

using namespace std;

int main() {
    string str;
    ifstream file("vehicles.txt");

    if (!file.is_open()) {
        cerr << "Error: Could not open the file 'vehicles.txt'." << endl;
        return 1;
    }
    
    while (getline(file, str)) {
        if (str.empty() || str[0] == '/' ) {
            continue;
        }
        
        cout << str << endl; 

        istringstream lineStream(str);

        string type, id, name, yearStr, extraData, certification;

        getline(lineStream, type, ',');
        getline(lineStream, id, ',');
        getline(lineStream, name, ',');
        getline(lineStream, yearStr, ',');
        getline(lineStream, extraData, ',');
        getline(lineStream, certification, ',');

        int year = stoi(yearStr);

        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year (string): " << yearStr << endl;
        cout << "Year (integer): " << year << endl;
        cout << "ExtraData: " << extraData << endl;
        cout << "Certification: " << certification << endl;

        size_t colonPos = extraData.find(':'); 
        size_t pipePos = extraData.find('|');  

        if (type == "AutonomousCar") {
            if (colonPos != string::npos) {
                string numberStr = extraData.substr(colonPos + 1);
                while (!numberStr.empty() && numberStr[0] == ' ') {
                    numberStr.erase(0, 1);
                }
                float softwareVersion = stof(numberStr);
                cout << "Software Version (float) for ID " << id << ": " << softwareVersion << endl;
            }
        }
        else if (type == "ElectricVehicle") {
            if (colonPos != string::npos) {
                string numberStr = extraData.substr(colonPos + 1);
                while (!numberStr.empty() && numberStr[0] == ' ') {
                    numberStr.erase(0, 1);
                }
                int batteryCapacity = stoi(numberStr);
                cout << "Battery Capacity (int) for ID " << id << ": " << batteryCapacity << endl;
            }
        }
        else if (type == "HybridTruck") {
            if (colonPos != string::npos && pipePos != string::npos) {
                string cargoStr = extraData.substr(colonPos + 1, pipePos - colonPos - 1);
                while (!cargoStr.empty() && cargoStr[0] == ' ') {
                    cargoStr.erase(0, 1);
                }
                int cargoCapacity = stoi(cargoStr);
                size_t secondColonPos = extraData.find(':', pipePos);
                if (secondColonPos != string::npos) {
                    string batteryStr = extraData.substr(secondColonPos + 1);
                    while (!batteryStr.empty() && batteryStr[0] == ' ') {
                        batteryStr.erase(0, 1);
                    }
                    int batteryCapacity = stoi(batteryStr);

                    cout << "Cargo Capacity (int) for ID " << id << ": " << cargoCapacity << endl;
                    cout << "Battery Capacity (int) for ID " << id << ": " << batteryCapacity << endl;
                } else {
                    cout << "Error: No second colon found after pipe for HybridTruck ExtraData!" << endl;
                }
            } else {
                cout << "Error: Missing colon or pipe in HybridTruck ExtraData!" << endl;
            }
        }
        else {
            cout << "Unknown vehicle type: " << type << endl;
        }

        cout << "--------------------------------------" << endl;
    }

    file.close();
    return 0;
}