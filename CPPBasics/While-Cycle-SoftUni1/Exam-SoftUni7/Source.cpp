#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()

{
    int gradesNumber; cin >> gradesNumber;
    int badGrades = 0;
    int totalNumber = 0;
    double totalGrades = 0;
    double average = 0.0;
    bool is_running = true;
    string lastProblem;
    string exerciseName;

    while (is_running)
    {
        lastProblem = exerciseName;
        if (badGrades >= gradesNumber)
        {
            cout << "You need a break, " << badGrades << " poor grades." << endl;
            return 0;
        }
        getline(cin >> ws, exerciseName);
        totalNumber++;
        if (exerciseName == "Enough")
        {
            totalNumber--;
            average = totalGrades / totalNumber;
            cout.setf(ios::fixed); cout << setprecision(2) << "Average score: " << average << endl;
            cout << "Number of problems: " << totalNumber << endl;
            cout << "Last problem: " << lastProblem << endl;
            return 0;
        }

        int currentGrade; cin >> currentGrade;

        if (currentGrade <= 4)
        {
            badGrades++;
        }
        totalGrades += currentGrade;
    }
    return 0;
}