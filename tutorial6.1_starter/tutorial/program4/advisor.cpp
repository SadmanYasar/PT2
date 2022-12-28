#include <iostream>
#include <string>
using namespace std;

#include "advisor.hpp"
#include "student.hpp"

Advisor::Advisor(string _name, string _staffId, string _department)
    : name(_name), staffId(_staffId), department(_department){}

string Advisor::getName() const { return name; }
string Advisor::getStaffId() const { return staffId; }
string Advisor::getDepartment() const { return department; }

void Advisor::addStudent(Student *student)
{
    /*__________*/
    /*__________*/
}

int Advisor::getStudentCount() const { /*__________*/ }

Student *Advisor::getStudent(int index) const
{
    /*__________*/
    /*__________*/
    /*__________*/
}

void Advisor::print() const
{
    cout << "Name       : " << name << endl;
    cout << "Staff ID   : " << staffId << endl;
    cout << "Department : " << department << endl;

    // Only print the student list if any
    
    /*__________*/

    cout << "Students Under Advisory: " << endl;
    /*__________*/
    /*__________*/
    
    cout << endl
         << endl;
}