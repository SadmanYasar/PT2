#include <iostream>
#include <string>
using namespace std;

#include "student.hpp"

Student::Student(string _name, string _matric)
    : name(_name), matric(_matric)
{
}

string Student::getName() const { return name; }
string Student::getMatric() const { return matric; }
Advisor *Student::getAdvisor() const
{ /*__________*/
}

void Student::setAdvisor(Advisor *_advisor)
{
    /*__________*/
    /*__________*/
}

void Student::print() const
{
    cout << "Name  : " << name << endl;
    cout << "Matric: " << matric << endl;

    // Only print advisor info if the student has been assigned one.

    /*__________*/

    cout << "Advisor: " << endl;
    cout << "   Name       : " /*__________*/ << endl;
    cout << "   Staff ID   : " /*__________*/ << endl;
    cout << "   Department : " /*__________*/ << endl;
    cout << endl
         << endl;
}
