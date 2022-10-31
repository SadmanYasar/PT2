#include <iostream>
using namespace std;

class Employee
{

private:
    string Name;
    string Company;
    int Age;

public:
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    void SayName()
    {
        cout << Name << endl;
    }
};

int main()
{
    Employee employee1 = Employee("Sayem", "IAYH", 19);
    employee1.SayName();

    return 0;
}