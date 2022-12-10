// Programming Technique II

//? EXERCISE 3: STRING MANIPULATIONS
//? file: custom_string.cpp

//!----------------------------------------------------------------------------------------
//! This is the only file that you will need to modify in this exercise.
//! Also, you will submit only this file.
//! This file is the implementation for the class CustomString.
//!----------------------------------------------------------------------------------------

// Member 1's Name: Sadman Yasar Sayem
// Member 2's Name: MD Mosakim Reza

#include <iostream>
#include <string>
using namespace std;

#include "custom_string.hpp"

//?----------------------------------------------------------------------------------------
//? The following methods are fully given: a constructor, getData() and setData()
//?----------------------------------------------------------------------------------------

CustomString::CustomString(const string &_data) : data(_data) {}
string CustomString::getData() const { return data; }
void CustomString::setData(const string &_data) { data = _data; }

//! Task 1: Complete the implementation of the following mutator methods:
//!        (a) pushFront()
//!        (b) pushBack()
//!        (c) pop()
//!        (d) popFront()
//!        (e) popBack()

void CustomString::pushFront(const string &s)
{
    data.insert(0, s);
}

void CustomString::pushBack(const string &s)
{
    data.append(s);
}

string CustomString::pop(int index, int count)
{
    string subString = data.substr(index, count);
    data = data.erase(index, count);
    return subString;
}

string CustomString::popFront(int count)
{
    string subString = data.substr(0, count);
    data = data.erase(0, count);
    return subString;
}

string CustomString::popBack(int count)
{
    string substring = data.substr(data.length() - count, count);
    data = data.erase(data.length() - count, count);
    return substring;
}

//! Task 2: Complete the implementation of the following overloaded operators:
//!        (a) operator !
//!        (b) operator *

CustomString CustomString::operator!() const
{
    string dataCopy = data;

    for (int i = 0; i < dataCopy.length(); i++)
    {
        int number = dataCopy.length() - i;
        dataCopy[i] = data[number - 1];
    }

    return CustomString(dataCopy);
}

CustomString CustomString::operator*(int count) const
{
    CustomString temp;
    string strCopy = this->data;
    temp.data = strCopy;

    for (int i = 0; i < count - 1; i++)
    {
        temp.pushBack(strCopy);
    }

    return temp;
}

//! Task 3: Complete the implementation of the following conversion methods:
//!        (a) toDouble()
//!        (b) toUpper()

double CustomString::toDouble() const
{
    return stod(data);
}

CustomString CustomString::toUpper() const
{
    string dataCopy = data;
    for (int i = 0; i < dataCopy.length(); i++)
    {
        dataCopy[i] = toupper(dataCopy[i]);
    }

    return CustomString(dataCopy);
}