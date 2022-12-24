//? EXERCISE 4: ASSOCIATION

// Programming Technique II

// Member 1's Name: _____________
// Member 2's Name: _____________

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________

// Video link:
//   _________

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_TERM_COUNT 10

class Term
{
private:
    int coef;
    int exp;

public:
    Term(int c = 0, int e = 0);
    void set(int c, int e);
    int evaluate(int x) const;
    int exponent() const;
    int coefficient() const;
};

class Polynomial
{
private:
    Term terms[MAX_TERM_COUNT];
    int count;

public:
    Polynomial();
    void input();
    int evaluate(int x) const;
    Term largestTerm() const;
    int degree() const;
    int getCount() const;
    void setCount(int c);
};

//----------------------------------------------------------------------------
int main()
{
    int noOfInputs = 0;
    Polynomial p;

    cout << "Enter a polynimial:" << endl;
    cout << "    \t\tHow many terms? => ";
    cin >> noOfInputs;
    cout << endl;

    p.setCount(noOfInputs);
    p.input();

    cout << endl;

    cout << " x  \t\tPolynomial value" << endl;
    cout << "----\t\t----------------" << endl;

    for (int x = 0; x <= 5; x++)
        cout << x << "  \t\t" << p.evaluate(x) << endl;

    cout << endl;

    system("pause");
    return 0;
}

//----------------------------------------------------------------------------
// class Term

// The constructor is given

Term::Term(int c, int e) : coef(c), exp(e) {}

// Implement the other methods
void Term::set(int c, int e)
{
    coef = c;
    exp = e;
}
int Term::exponent() const { return exp; }
int Term::coefficient() const { return coef; }
int Term::evaluate(int x) const { return coef * pow(x, exp); }
//----------------------------------------------------------------------------

// class Polynomial

// Implement the constructor and the other methods of the class Polynomial
Polynomial::Polynomial()
{
    count = 0;
}

int Polynomial::evaluate(int x) const
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += terms[i].evaluate(x);
    }

    return sum;
}

int Polynomial::getCount() const { return count; }
void Polynomial::setCount(int c)
{
    count = c;
}

void Polynomial::input()
{
    for (int i = 0; i < count; i++)
    {
        int coefficient;
        int exponent;
        cout << "    \t\tEnter term #" << i << " (coef and exp) => ";
        cin >> coefficient >> exponent;

        this->terms[i].set(coefficient, exponent);
        cout << endl;
    }
}

Term Polynomial::largestTerm() const
{
}
int Polynomial::degree() const
{
}
