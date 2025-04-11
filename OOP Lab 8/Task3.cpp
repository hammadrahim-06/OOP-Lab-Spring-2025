#include <iostream>
#include <string>
using namespace std;

class Teacher;

class Student {
    private:
    string fullName;
    int marks[3];

    public:
    Student(string n, int m1, int m2, int m3) {
        fullName = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    friend class Teacher;
    friend float calculateAverageGrade(const Student&);
};

class Teacher {
    public:
    void printMarks(const Student& s) {
        cout << "Student: " << s.fullName << endl;
        cout << "Recorded Scores: ";
        for (int i = 0; i < 3; ++i) {
            cout << s.marks[i] << (i < 2 ? " | " : "");
        }
        cout << endl;
    }

    void reviseMark(Student& s, int pos, int updatedMark) {
        if (pos >= 0 && pos < 3) {
            s.marks[pos] = updatedMark;
            cout << "Score #" << pos + 1 << " changed to " << updatedMark << "." << endl;
        } else {
            cout << "Position out of range." << endl;
        }
    }
};

float calculateAverageGrade(const Student& s) {
    float sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += s.marks[i];
    }
    return sum / 3.0f;
}

int main() {
    Student st1("Ryan Taylor", 67, 74, 81);
    Teacher instructor;

    cout << "--- Score Overview ---" << endl;
    instructor.printMarks(st1);
    cout << "Average Before Update: " << calculateAverageGrade(st1) << endl;
    cout << "\nMaking adjustments..." << endl;
    instructor.reviseMark(st1, 0, 88);
    cout << "\n--- Post-Update Report ---" << endl;
    instructor.printMarks(st1);
    cout << "New Average: " << calculateAverageGrade(st1) << endl;

    return 0;
}