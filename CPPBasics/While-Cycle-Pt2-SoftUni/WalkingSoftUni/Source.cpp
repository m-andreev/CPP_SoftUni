#include <iostream>
#include <string>

using namespace std;

int main()
{
    int totalSteps;
    cin >> totalSteps;
    string stepsDuringDay = "";
    int steps2home = 0 ;

    while (totalSteps < 10000)
    {
        getline(cin >> ws,stepsDuringDay);

        if (stepsDuringDay == "Going home")
        {
            break; ///// Breaks the loop !!!!!!
        }
            int stepsDay = stoi(stepsDuringDay);
            totalSteps += stepsDay;

    }

    if (stepsDuringDay == "Going home")
    {
        cin >> steps2home;
        totalSteps += steps2home;
        if (totalSteps >= 10000)
        {
            cout << "Goal reached! Good job!" << endl;
        }
        else
        {
            cout << 10000 - totalSteps << " more steps to reach goal." << endl;
        }
    }
    else
    {
        cout << "Goal reached! Good job!" << endl;
    }
    return 0;
}