#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    string matric;
    int score;

public:
    int count = 0;
    Student(string _name = "", string _matric = "", int _score = 0) : name(_name),
                                                                      matric(_matric),
                                                                      score(_score) {}
    string getName() const
    {
        return name;
    }
    friend void log(const Student &);

    int operator+(Student &s)
    {
        return this->score + s.score;
    }

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
    Student studs[4] = {
        Student(),
        Student("lol", "ok", 66)};
    /* Student *s1 = new Student("LOL", "132", 10);
                   Student s2("WTF", "12", 30);
                   Student s3("WTFF", "122", 30);
                   cout << s1->getName() << endl;
                   incrementCount(s1);
                   cout << s1->count << endl;

                   cout << s1->operator+(s2) << endl;
                   cout << s2 + s3 << endl;
                   delete s1; */

    system("pause");
    return 0;
}