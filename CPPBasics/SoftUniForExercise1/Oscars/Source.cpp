#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//	Име на актьора - текст
	//	Точки от академията - реално число в интервала[2.0... 450.5]
	//	Брой оценяващи n - цяло число в интервала[1… 20]

	string actorName;
	double pointsAcad;
	int n; ///// Num of evaluators

	getline(cin >> ws, actorName);
	cin >> pointsAcad >> n;

	string evaluatorName;
	double evaluatorPoints;

	cout.setf(ios::fixed);
	cout.precision(1);

	for (size_t i = 1; i <= n; i++)
	{
		getline(cin >> ws, evaluatorName);
		cin >> evaluatorPoints;

		int evaluatorNameLength = evaluatorName.length();
		pointsAcad += evaluatorPoints * evaluatorNameLength / 2;

		if (pointsAcad >= 1250.5)
		{
			cout << "Congratulations, " << actorName << " got a nominee for leading role with " << pointsAcad << "!"<<endl;
			return 0;
		}

	}

	double diff = 1250.5 - pointsAcad;
	cout << "Sorry, " << actorName << " you need " << diff << " more!" << endl;
	
	return 0;
}