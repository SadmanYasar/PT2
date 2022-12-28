// Problem 4

#include "advisor.hpp"
#include "student.hpp"

int main()
{
    //! Create an advisor object and three students object
    //!  assign the advisor to only to two students.

    Advisor adv("Dr. Razali", "1783", "School of Computing");
    Student stud1("Ahmad", "A19CS22343");
    Student stud2("Kamal", "A21CS342233");
    Student stud3("Zahid", "A16CS432343");

    /*__________*/
    /*__________*/
    
    stud1.print();
    stud2.print();
    stud3.print();

    adv.print();

    system("pause");
    return 0;
}