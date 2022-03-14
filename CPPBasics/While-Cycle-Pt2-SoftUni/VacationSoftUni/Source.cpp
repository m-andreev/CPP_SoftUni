#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool running = true;
    double neededMoney = 0.0;
    double availableMoney = 0.0;
    cin >> neededMoney >> availableMoney;
    double totalSum = 0.0;
    int spendDaysCounter = 0;
    int totalDays = 0;

    while(running)
    {
        string input;
        cin >> input;
        double sumInput;
        cin >> sumInput;
        totalDays++;
        if (input == "save")
        {
            availableMoney += sumInput;
            spendDaysCounter = 0;
        }
        if (input == "spend")
        {
            availableMoney -= sumInput;
            spendDaysCounter++;
            if (spendDaysCounter == 5)
            {
                cout << "You can't save the money."<<endl;
                cout << totalDays;
                return 0;
            }
            if (sumInput >= availableMoney)
            {
                availableMoney = 0;
            }
        }
        if (availableMoney >= neededMoney)
        {
            cout << "You saved the money for "<<totalDays <<" days." << endl;
            break;
        }
    }
    return 0;
}