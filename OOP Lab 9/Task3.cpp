#include "book.h"
#include <iostream>
using namespace std;

int main() {
    Library lib;

    Book* b1 = new Book("The Pragmatic Programmer", "Andrew Hunt", "111222");
    Book* b2 = new Book("Introduction to Algorithms", "Cormen et al.", "333444");
    Book* b3 = new Book("Refactoring", "Martin Fowler", "555666");

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    cout << "Initial Library:" << endl;
    lib.displayAllBooks();

    lib.removeBook("Introduction to Algorithms");

    cout << endl << "After removing second book:" << endl;
    lib.displayAllBooks();

}