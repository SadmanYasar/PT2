#include <iostream>
#include <string>
using namespace std;

double divide(int, int);

int main()
{
    int num1, num2;
    double quotient;

    cout << "Enter 2 numbers \n";
    cin >> num1 >> num2;

    try
    {
        quotient = divide(num1, num2);
        cout << "The quotient is " << quotient << endl;
    }
    catch (string exceptionString)
    {
        cout << exceptionString << endl;
    }
    system("pause");
    return 0;
}

/*
=============================================
 The divide function divides the numerator
 by the denominator. If the denominator is
 zero, the function throws an exception.

 IMP - throw must return string variable

 cant do like this:
    throw "Error message"

but like this:
    string exceptionString = "Error message";
    throw exceptionString;
=============================================
*/
double divide(int numerator, int denominator)
{
    if (denominator == 0)
    {
        string exceptionString = "ERROR: Cannot divide by 0";
        throw exceptionString;
    }

    return static_cast<double>(numerator) / denominator;
}