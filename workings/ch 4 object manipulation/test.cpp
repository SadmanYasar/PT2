#include <iostream>
using namespace std;

int main()
{
    string secret = "twenty";
    string guess;
    cin >> guess;

    if (secret.compare(guess) > 0)
    {
        cout << "hello" << endl;
    }

    system("pause");

    return 0;
}