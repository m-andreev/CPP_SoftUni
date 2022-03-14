#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main()
{
    string input;
    cin >> input;

    int min = INT_MAX;

    while (input != "Stop")
    {
        int number = stoi(input);
        if (number < min)
        {
            min = number;

        }

        cin >> input;

    }
    cout << min << endl;


    return 0;
}