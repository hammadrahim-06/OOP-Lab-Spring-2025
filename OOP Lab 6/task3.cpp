#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    void displayDetails() {
        cout << "Name: " << name << " | Age: " << age;
    }
};

class Teacher : virtual public Person {
protected:
    string subject;

public:
    Teacher(string n, int a, string s) : Person(n, a) {
        subject = s;
    }
    void displayDetails() {
        Person::displayDetails();
        cout << " | Subject: " << subject;
    }
};

class Researcher : virtual public Person {
protected:
    string researchArea;

public:
    Researcher(string n, int a, string ra) : Person(n, a) {
        researchArea = ra;
    }
    void displayDetails() {
        Person::displayDetails();
        cout << " | Research Area: " << researchArea;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(string n, int a, string s, string ra, int p)
        : Person(n, a), Teacher(n, a, s), Researcher(n, a, ra) {
        publications = p;
    }
    
    void displayDetails() {
        Person::displayDetails();
        cout << " | Subject: " << subject;
        cout << " | Research Area: " << researchArea;
        cout << " | Publications: " << publications << endl;
    }
};

int main() {
    string name, subject, researchArea;
    int age, publications;

    cout << "Enter Professor's Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Subject Expertise: ";
    cin >> subject;
    cout << "Enter Research Area: ";
    cin >> researchArea;
    cout << "Enter Number of Publications: ";
    cin >> publications;

    Professor prof(name, age, subject, researchArea, publications);
    prof.displayDetails();

    return 0;
}