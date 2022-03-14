#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int n; cin >> n; ///number of the people in the jury which gives evaluation
	string presentation; getline(cin >> ws, presentation); /// presentation name
	double everyEvaluation = 0.0;
	int counter=0;

	cout.setf(ios::fixed);
	cout.precision(2);
	while (presentation != "Finish")
	{
		if (presentation == "Finish")
		{
			break;
		}
	   double totalEvaluation = 0.0;
	   for (int i = 1; i <= n; i++)
	   {
		  double evaluation;
		  cin >> evaluation;
		  totalEvaluation += evaluation;
		  everyEvaluation += evaluation;
		  counter++;
	   }
	   cout << presentation << " - " << totalEvaluation / n << "." << endl;
	   getline(cin >> ws, presentation);
    }
	cout << "Student's final assessment is " << everyEvaluation/counter << "." << endl;

	return 0;
}