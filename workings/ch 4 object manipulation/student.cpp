#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    string matric;

public:
    int count = 0;
    Student(string _name, string _matric) : name(_name), matric(_matric) {}
    string getName() const
    {
        return name;
    }
    friend void log(const Student &);
    ~Student()
    {
    }
};

void incrementCount(Student *s)
{
    s->count++;
}

void log(const Student &student)
{
    cout << student.name << endl;
}

int main()
{
    Student *s1 = new Student("LOL", "132");
    cout << s1->getName() << endl;
    incrementCount(s1);
    cout << s1->count << endl;
    delete s1;

    system("pause");
    return 0;
}