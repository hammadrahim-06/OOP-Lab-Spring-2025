#include <iostream>
#include <fstream>
using namespace std;

int main() {
	string str;
	ifstream file;
	file.open("vehicles.txt");
	
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
	file.close();
	
	return 0;
}