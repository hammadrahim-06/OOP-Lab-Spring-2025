#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>

using namespace std;

int main() {
    string str;
    ifstream file("vehicles.txt");

   if (!file.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }
    
    while (getline(file, str)) {
        if (str.empty() || str[0] == '/' ) {
            continue;
        }
        cout << str << endl;
	}
        istringstream lineStream(str);

        string type, id, name, year, extraData, certification;

        getline(lineStream, type, ',');
        getline(lineStream, id, ',');
        getline(lineStream, name, ',');
        getline(lineStream, year, ',');
        getline(lineStream, extraData, ',');
        getline(lineStream, certification, ',');

        cout << "\nType: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "ExtraData: " << extraData << endl;
        cout << "Certification: " << certification << endl;
    

    file.close();
    return 0;
}