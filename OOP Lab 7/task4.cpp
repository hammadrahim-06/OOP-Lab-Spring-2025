#include <iostream>
using namespace std;

class Person {
    protected:
    string name;
    int id;
    string address;
    string phoneNumber;
    string email;

    public:
    Person(string n, int Id, string add, string num, string mail)  : name(n), id(Id), address(add), phoneNumber(num), email(mail) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(string add, string num, string mail) {
        address = add;
        phoneNumber = num;
        email = mail;
        cout << "Information Updated Successfully!" << endl;
    }

    string getName() { 
        return name;
    }
};

class Student : public Person {
    private:
    double GPA;
    int enrollmentYear;
    string coursesEnrolled[5]; 
    int courseCount;

    public:
    Student(string n, int Id, string add, string num, string mail, double gpa, int year) : Person(n, Id, add, num, mail), GPA(gpa), enrollmentYear(year), courseCount(0) {}

    void enrollCourse(string course) {
        if (courseCount < 5) {
            coursesEnrolled[courseCount++] = course;
        } else {
            cout << "Cannot enroll in more than 5 courses!" << endl;
        }
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "Courses Enrolled: ";
        for (int i = 0; i < courseCount; i++) {
            cout << coursesEnrolled[i] << " ";
        }
        cout << endl;
    }
};

class Professor : public Person {
    private:
    string department;
    string coursesTaught[3]; 
    int courseCount;
    double salary;

    public:
    Professor(string n, int Id, string add, string num, string mail, string dept, double sal) : Person(n, Id, add, num, mail), department(dept), salary(sal), courseCount(0) {}

    void assignCourse(string course) {
        if (courseCount < 3) {
            coursesTaught[courseCount++] = course;
        } else {
            cout << "Cannot teach more than 3 courses!" << endl;
        }
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: ";
        for (int i = 0; i < courseCount; i++) {
            cout << coursesTaught[i] << " ";
        }
        cout << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Staff : public Person {
    private:
    string department;
    string position;
    double salary;

    public:
    Staff(string n, int Id, string add, string num, string mail, string dept, string pos, double sal) : Person(n, Id, add, num, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Course {
    private:
    int courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;
    Student *enrolledStudents[10];  
    int studentCount;

    public:
    Course(int id, string name, int cr, string instr, string sched) : courseId(id), courseName(name), credits(cr), instructor(instr), schedule(sched), studentCount(0) {}

    void registerStudent(Student *s) {
        if (studentCount < 10) {
            enrolledStudents[studentCount++] = s;
            s->enrollCourse(courseName);
            cout << s->getName() << " enrolled in " << courseName << endl; 
        } else {
            cout << "Course is full!" << endl;
        }
    }

    void displayCourseDetails() {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
        cout << "Enrolled Students: ";
        for (int i = 0; i < studentCount; i++) {
            cout << enrolledStudents[i]->getName() << " "; // ✅ Using getter function
        }
        cout << endl;
    }
};

int main() {
    Student s1("Ahmed Ali", 101, "Karachi, Pakistan", "0312-1234567", "ahmed@example.com", 3.7, 2022);
    Student s2("Sara Khan", 102, "Lahore, Pakistan", "0321-6543210", "sara@example.com", 3.9, 2021);
    
    Professor p1("Dr. Farooq", 201, "Lahore, Pakistan", "042-5678910", "farooq@example.com", "Computer Science", 150000);
    
    Staff st1("Ayesha Khan", 301, "Islamabad, Pakistan", "051-9876543", "ayesha@example.com", "Administration", "Manager", 120000);
    
    Course c1(501, "Object-Oriented Programming", 3, "Dr. Farooq", "MWF 10:00AM-11:30AM");
    Course c2(502, "Data Structures", 4, "Dr. Farooq", "TTh 1:00PM-2:30PM");

    c1.registerStudent(&s1);
    c2.registerStudent(&s2);

    p1.assignCourse("Object-Oriented Programming");
    p1.assignCourse("Data Structures");

    cout << "\n=== Displaying University Details ===\n";
    s1.displayInfo();
    cout << endl;
    s2.displayInfo();
    cout << endl;
    p1.displayInfo();
    cout << endl;
    st1.displayInfo();
    cout << endl;
    
    cout << "=== Course Details ===" << endl;
    c1.displayCourseDetails();
    cout << endl;
    c2.displayCourseDetails();
    
    return 0;
}