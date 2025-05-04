#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream logFile("large_log.txt");
    if (!logFile) {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;
    }
    logFile << "This is the first part of the log.\n";
    logFile << "This is the second part of the log.\n";
    logFile << "And the third part.";
    logFile.close();

    ifstream inputFile("large_log.txt");
    if (!inputFile) {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;
    }

    char buffer1[11] = {}; 
    inputFile.read(buffer1, 10);
    cout << "First read (10 chars): " << buffer1 << endl;

    streampos pos1 = inputFile.tellg();
    cout << "Position after first read: " << pos1 << endl;

    char buffer2[11] = {}; 
    inputFile.read(buffer2, 10);
    cout << "Second read (next 10 chars): " << buffer2 << endl;

    streampos pos2 = inputFile.tellg();
    cout << "Position after second read: " << pos2 << endl;

    inputFile.close();

    return 0;
}