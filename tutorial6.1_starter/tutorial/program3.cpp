// Problem 3

#include <iostream>
#include <string>
using namespace std;

class Course
{
private:
    string code;
    string name;

public:
    Course(string _code = "", string _name = "") : code(_code), name(_name) {}
    string getCode() const { return code; }
    string getName() const { return name; }
};

#define MAX 5

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

    int getCourseCount() const
    { /*_________*/
    }

    Course *getCourse(int index) const
    {
        /*_________*/
    }

    void enrollCourse(Course *course)
    {
        /*_________*/
    }

    void print() const
    {
        cout << "Name  : " << name << endl;
        cout << "Matric: " << matric << endl;

        // Only print courses info if the student has enrolled any.

        cout << endl;
        cout << "Courses Enrolled: " << endl;
        
        cout << endl
             << endl;
    }
};

int main()
{
    //! Create two students and enroll the first student with several courses.
    //! No courses enrolled by the second student.

    Student stud1("Ahmad", "A19CS22343");
    Student stud2("Kamal", "A21CS342233");

    // sample course data
    // ("SECJ1023", "C++ Programming")
    // ("SECJ3623", "Flutter Programming")
    // ("SECV2223", "JavaScript Programming")

    stud1.print();
    stud2.print();
    cout << endl;

    system("pause");
    return 0;
}