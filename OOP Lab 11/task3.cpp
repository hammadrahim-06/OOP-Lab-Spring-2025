#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
using namespace std;

class FileAccessError : public exception {

    public:
        virtual const char* what() const noexcept override {
            return "FileAccessError - Unable to access file due to unknown issue.";
        }

};

class MissingFileError : public FileAccessError {

    public:
        const char* what() const noexcept override {
            return "MissingFileError - The specified file does not exist.";
        }

};

class AccessDeniedError : public FileAccessError {

    public:
        const char* what() const noexcept override {
            return "AccessDeniedError - Permission denied while opening file.";
        }

};

int main() {

    ifstream inputStream;

    try {
        inputStream.open("secret.txt");
        if(!inputStream.is_open()) {
            if (errno == ENOENT) {
                throw MissingFileError();
            } else if (errno == EACCES) {
                throw AccessDeniedError();
            } else {
                throw FileAccessError();
            }
        }
        cout << "File successfully opened!" << endl;
    } catch(FileAccessError& errObj) {
        cout << errObj.what() << endl;
        return 0;
    }

    inputStream.close();

}