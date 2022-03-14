#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main()
{
    string input;
    cin >> input;

    int max = INT_MIN;

    while (input != "Stop")
    {
        int number = stoi(input);
        if (number > max)
        {
            max = number;

        }

        cin >> input;

    }
    cout << max << endl;


    return 0;
}