#ifndef ADVISOR_H
#define ADVISOR_H

#include <string>
using namespace std;

#define MAX_STUDENT 10

class Student; // use foward declaration here instead of include "student.hpp"

class Advisor
{
private:
    string name;
    string staffId;
    string department;

   /*________*/
   /*________*/

public:
    Advisor(string _name = "", string _staffId = "", string _department = "");
    string getName() const;
    string getStaffId() const;
    string getDepartment() const;

    void addStudent(Student *student);

    int getStudentCount() const;
    Student *getStudent(int index) const;
    void print() const;
};

#endif