#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream configFile("config.txt");
    if (!configFile) {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;
    }
    configFile << "AAAAABBBBBCCCCC";
    configFile.close();

    fstream configFileRW("config.txt", ios::in | ios::out);
    if (!configFileRW) {
        cerr << "Error: Could not open file for reading and writing." << endl;
        return 1;
    }

    configFileRW.seekp(5);
    configFileRW << "XXXXX";

    configFileRW.close();

    ifstream configFileRead("config.txt");
    if (!configFileRead) {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;
    }

    string content;
    getline(configFileRead, content);
    cout << "Updated config.txt content: " << content << endl;

    configFileRead.close();

    return 0;
}