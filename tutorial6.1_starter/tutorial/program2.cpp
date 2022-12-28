// Problem 2

#include <iostream>
#include <string>
using namespace std;

class Advisor
{
private:
    string name;
    string staffId;
    string department;

public:
    Advisor(string _name = "", string _staffId = "", string _department = "")
        : name(_name), staffId(_staffId), department(_department) {}
    string getName() const { return name; }
    string getStaffId() const { return staffId; }
    string getDepartment() const { return department; }
};

class Student
{
private:
    string name;
    string matric;

public:
    Student(string _name = "", string _matric = "")
        : name(_name), matric(_matric) {}
    string getName() const { return name; }
    string getMatric() const { return matric; }

    void print() const
    {
        cout << "Name  : " << name << endl;
        cout << "Matric: " << matric << endl;

        // Only print advisor info if the student has been assigned one.
        cout << "Advisor: " << endl;
        cout << "   Name       : " <<  endl;
        cout << "   Staff ID   : " << endl;
        cout << "   Department : " << endl;
        cout << endl << endl;
    }
};

int main()
{
    //! Create an advisor object and three students object
    //!  assign the advisor to only to two students.

    Advisor adv;
    Student stud1;
    Student stud2;
    Student stud3;

    stud1.print();
    stud2.print();
    stud3.print();

    system("pause");
    return 0;
}