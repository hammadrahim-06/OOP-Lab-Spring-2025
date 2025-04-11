#include <iostream>
#include <string>
using namespace std;

class Librarian;

class Book {
    private:
    string bookTitle;
    float bookCost;

    public:
    Book(string name, float cost) : bookTitle(name), bookCost(cost) {}

    friend class Librarian;
};

class Librarian {
    public:
    void showDetails(const Book& b) {
        cout << "Title: " << b.bookTitle << endl;
        cout << "Current Price: $" << b.bookCost << endl;
    }

    void adjustPrice(Book& b, float percentageOff) {
        float reduced = b.bookCost * (percentageOff / 100.0);
        b.bookCost -= reduced;
        cout << "Discount of " << percentageOff << "% has been applied." << endl;
    }
};

int main() {
    Book myBook("Mastering C++", 65.0);
    Librarian staff;

    cout << "*** Book Information ***" << endl;
    staff.showDetails(myBook);

    cout << "\nProcessing discount..." << endl;
    staff.adjustPrice(myBook, 15.0);

    cout << "\n*** Updated Information ***" << endl;
    staff.showDetails(myBook);

    return 0;
}