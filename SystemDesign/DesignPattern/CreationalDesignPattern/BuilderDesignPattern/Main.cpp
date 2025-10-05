#include<iostream>

using namespace std;

class Student {
    public:
        string name;
        int rollNo;
        string department;

        Student() {
            name="Default";
            rollNo=0;
            department="Default";
        }

        void showDetails() {
            cout << "Name: " << name << " Roll No.: " << rollNo << " Department: " << department << endl;
        }
};

class StudentBuilder {
    private:
        Student* student;

    public:
        StudentBuilder() {
            student = new Student();
        }
        StudentBuilder* setName(string name) {
            student->name = name;
            return this;
        }
        StudentBuilder* setRollNo(int rollNo) {
            student->rollNo = rollNo;
            return this;
        }
        StudentBuilder* setDepartment(string department) {
            student->department = department;
            return this;
        }
        Student* build() {
            return student;
        }
};

int main() {
    StudentBuilder* studentBuilder = new StudentBuilder();
    Student* s1 = studentBuilder->setName("Lav")->build();
    s1->showDetails();
    s1 = studentBuilder->setName("Lav")->setRollNo(10)->build();
    s1->showDetails();
    s1 = studentBuilder->setName("Lav")->setDepartment("INFT")->build();
    s1->showDetails();
    return 0;
}