#include <iostream>
#include <fstream>
#include <cstring> 

using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem itemToWrite;
    itemToWrite.itemID = 101;
    strcpy(itemToWrite.itemName, "Laptop");
    ofstream outFile("inventory.dat", ios::binary);
    if (!outFile) {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;
    }
    outFile.write(reinterpret_cast<char*>(&itemToWrite), sizeof(itemToWrite));
    outFile.close();
    cout << "Item written to file successfully." << endl;

    InventoryItem itemToRead;

    ifstream inFile("inventory.dat", ios::binary);
    if (!inFile) {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;
    }
    inFile.read(reinterpret_cast<char*>(&itemToRead), sizeof(itemToRead));
    inFile.close();

    cout << "Item loaded from file:" << endl;
    cout << "Item ID: " << itemToRead.itemID << endl;
    cout << "Item Name: " << itemToRead.itemName << endl;

    return 0;
}