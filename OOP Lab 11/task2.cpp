#include <iostream>
using namespace std;

#define STACK_CAPACITY 4

class StackLimitExceeded : public exception {
  
    public:
        const char* what() const noexcept override {
            return "StackLimitExceeded - Cannot add more elements!";
        }

};

class StackEmptyAccess : public exception {
  
    public:
        const char* what() const noexcept override {
            return "StackEmptyAccess - Cannot remove from an empty stack!";
        }

};

template <typename U>
class CustomStack {
    private:
        U storage[STACK_CAPACITY];
        int topIndex;
    public:
        CustomStack() : topIndex(-1) {}

        void insert(U item) {
            if(topIndex < STACK_CAPACITY - 1) {
                topIndex++;
                storage[topIndex] = item;
                cout << "Item: " << storage[topIndex] << " inserted at position " << topIndex << endl;
            } else {
                throw StackLimitExceeded();
            }
        }

        void remove() {
            if(topIndex >= 0) {
                cout << "Item: " << storage[topIndex] << " removed from position " << topIndex << endl;
                topIndex--;
            } else {
                throw StackEmptyAccess();
            }
        }
};

int main() {

    CustomStack<double> myStack;

    try {
        for(int idx = 0; idx < STACK_CAPACITY + 2; idx++) {
            myStack.insert(idx * 0.1);
        }       
    } catch(const StackLimitExceeded& err) {
        cout << "Error: " << err.what() << endl;
    }

    try {
        for(int idx = 0; idx < STACK_CAPACITY + 2; idx++) {
            myStack.remove();
        }
    } catch(const StackEmptyAccess& err) {
        cout << "Error: " << err.what() << endl;
    }

}