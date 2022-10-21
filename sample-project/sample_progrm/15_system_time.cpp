
// Program : This program shows how to use system's time
//
// jumail@utm.my
// 15 Dec 2018

#include<iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t start, now;
    tm* current;

    int year, month, day;
    int hour, minute, second;

    double timeElapsed;  // in seconds. we use double here as the value is in seconds

    time(&start);  // read the current time from the system, for the starting time

    while (true){

        time(&now);  // read the current time from the system
        tm* current =  localtime(&now);  // to parse time's component to year, month, day, hour and so on
        timeElapsed = difftime(now, start);

        year = current->tm_year + 900;
        month = current->tm_mon + 1;
        day = current->tm_mday;
        hour = current->tm_hour;
        minute = current->tm_min;
        second = current->tm_sec;

        cout << "Current date : " << day << "/" << month << "/" << year << endl;
        cout << "Current time : " << hour<< ":" << minute << ":" << second << endl;
        cout << timeElapsed << " seconds has elapsed" << endl;

        for (int sleep=0; sleep<1000; sleep++); // a delay

        system("cls");  // to clear the screen
    }

    system("pause");
    return 0;
}
