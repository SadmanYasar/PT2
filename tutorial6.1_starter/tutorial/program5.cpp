#include <iostream>
#include <string>
using namespace std;


class Staff
{
private:
    string name;
    string id;
    string faculty;
    string position;

    string city;
    string state;
    string postCode;

public:
    Staff(string _name = "", string _id = "",
          string _faculty = "Faculty of Engineering", string _position = "Lecturer",
          string _city = "Johor Bahru", string _state = "Johor", string _postCode = "81310")
        : name(_name), id(_id), faculty(_faculty), position(_position),
          city(_city), state(_state), postCode(_postCode) {}

    string getName() const { return name; }
    string getId() const { return id; }
    string getFaculty() const { return faculty; }
    string getPosition() const { return position; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getPostCode() const { return postCode; }

    void setName(string _name) { name = _name; }
    void setId(string _id) { id = _id; }
    void setFaculty(string _faculty) { faculty = _faculty; }
    void setPosition(string _position) { position = _position; }
    void setCity(string _city) { city = _city; }
    void setState(string _state) { state = _state; }
    void setSPostCode(string _postCode) { postCode = _postCode; }
};

class Student
{
private:
    string name;
    string matric;
    string faculty;
    string program;

    string city;
    string state;
    string postCode;

public:
    Student(string _name = "", string _matric = "",
            string _faculty = "Faculty of Engineering", string _program = "Software Engineering",
            string _city = "Johor Bahru", string _state = "Johor", string _postCode = "81310")
        : name(_name), matric(_matric), faculty(_faculty), program(_program),
          city(_city), state(_state), postCode(_postCode) {}

    string getName() const { return name; }
    string getMatric() const { return matric; }
    string getFaculty() const { return faculty; }
    string getProgram() const { return program; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getPostCode() const { return postCode; }

    void setName(string _name) { name = _name; }
    void setMatric(string _matric) { matric = _matric; }
    void setFaculty(string _faculty) { faculty = _faculty; }
    void setProgram(string _program) { program = _program; }
    void setCity(string _city) { city = _city; }
    void setState(string _state) { state = _state; }
    void setSPostCode(string _postCode) { postCode = _postCode; }
};

int main()
{
    return 0;
}