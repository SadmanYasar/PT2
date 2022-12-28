#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

#include "advisor.hpp"

class Student
{
private:
    string name;
    string matric;
    
    /*__________*/

public:
    Student(string _name = "", string _matric = "");
    string getName() const;
    string getMatric() const;
    Advisor *getAdvisor() const;

    void setAdvisor(Advisor *_advisor);

    void print() const;
};

#endif