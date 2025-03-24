#include <iostream>
#include <string>
using namespace std;

class Media {
    protected:
    string title;
    string publicationDate;
    int uniqueID;
    string publisher;
    bool isBorrowed;

    public:
    Media(string t, string date, int id, string pub) : title(t), publicationDate(date), uniqueID(id), publisher(pub), isBorrowed(false) {}

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }

    void checkOut() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << "\"" << title << "\" has been borrowed.\n";
        } else {
            cout << "\"" << title << "\" is already borrowed.\n";
        }
    }

    void returnItem() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << "\"" << title << "\" has been returned.\n";
        } else {
            cout << "\"" << title << "\" was not borrowed.\n";
        }
    }

    string getTitle() { return title; }
    string getPublicationDate() { return publicationDate; }
};

class Book : public Media {
    private:
    string author;
    string isbn;
    int numberOfPages;

    public:
    Book(string t, string date, int id, string pub, string auth, string isbnNum, int pages): Media(t, date, id, pub), author(auth), isbn(isbnNum), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
    private:
    string director;
    int duration;
    double rating;

    public:
    DVD(string t, string date, int id, string pub, string dir, int dur, double rate) : Media(t, date, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << "/10" << endl;
    }
};

class CD : public Media {
    private:
    string artist;
    int numberOfTracks;
    string genre;

    public:
    CD(string t, string date, int id, string pub, string art, int tracks, string gen) : Media(t, date, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

class Magazine : public Media {
    public:
    Magazine(string t, string date, int id, string pub) : Media(t, date, id, pub) {}

    void displayInfo() override {
        Media::displayInfo();
    }
};

void searchMedia(Media *library[], int size, string title) {
    for (int i = 0; i < size; i++) {
        if (library[i]->getTitle() == title) {
            cout << "Media Found:\n";
            library[i]->displayInfo();
            return;
        }
    }
    cout << "No match found for title: " << title << ".\n";
}

void searchMedia(Media *library[], int size, string title, string year) {
    for (int i = 0; i < size; i++) {
        if (library[i]->getTitle() == title && library[i]->getPublicationDate().substr(0, 4) == year) {
            cout << "Media Found:\n";
            library[i]->displayInfo();
            return;
        }
    }
    cout << "No match found for \"" << title << "\" published in " << year << ".\n";
}

int main() {
    Book book1("Urdu Ki Duniya", "2023-07-21", 101, "Oxford University Press", "Faizan Ahmed", "978-1234567890", 350);
    DVD dvd1("Parwaaz Hai Junoon", "2018-08-22", 201, "Hum Films", "Haseeb Hassan", 130, 8.1);
    CD cd1("Coke Studio Hits", "2022-12-05", 301, "Coke Studio Pakistan", "Atif Aslam", 12, "Pop");
    Magazine mag1("Herald", "2024-03-10", 401, "Dawn Media Group");

    Media *libraryCollection[] = {&book1, &dvd1, &cd1, &mag1};
    int totalMedia = sizeof(libraryCollection) / sizeof(libraryCollection[0]);

    cout << "\nLibrary Catalog:\n";
    for (int i = 0; i < totalMedia; i++) {
        libraryCollection[i]->displayInfo();
        cout << "--------------------------\n";
    }

    cout << "\nBorrowing Items:\n";
    book1.checkOut();
    dvd1.checkOut();

    cout << "\nReturning Items:\n";
    book1.returnItem();
    dvd1.returnItem();

    cout << "\nSearching for Media:\n";
    searchMedia(libraryCollection, totalMedia, "Parwaaz Hai Junoon");
    searchMedia(libraryCollection, totalMedia, "Coke Studio Hits", "2022");

    return 0;
}