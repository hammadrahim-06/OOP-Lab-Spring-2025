#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream dataFile("data_records.txt");
    if (!dataFile) {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;
    }
    dataFile << "Record 1\n";
    dataFile << "Record 2\n";
    dataFile << "Record 3\n";
    dataFile << "Record 4\n";
    dataFile.close();

    ifstream inputFile("data_records.txt");
    if (!inputFile) {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;
    }

    inputFile.seekg(18, ios::beg);
    string record;
    getline(inputFile, record);

    cout << "Third Record: " << record << endl;

    inputFile.close();

    return 0;
}