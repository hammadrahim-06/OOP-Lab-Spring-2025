#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("vehicles.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.empty() || line[0] == '#' || (line.size() >= 2 && line[0] == '/' && line[1] == '/')) {
            continue;
        }

        istringstream lineStream(line);

        string type, id, name, yearStr, extraData, certification;

        getline(lineStream, type, ',');
        getline(lineStream, id, ',');
        getline(lineStream, name, ',');
        getline(lineStream, yearStr, ',');
        getline(lineStream, extraData, ',');
        getline(lineStream, certification, ',');

        int year = stoi(yearStr); 

        cout << "\nType: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year (string): " << yearStr << endl;
        cout << "Year (integer): " << year << endl; 
        cout << "ExtraData: " << extraData << endl;
        cout << "Certification: " << certification << endl;
    }

    inputFile.close();
    return 0;
}