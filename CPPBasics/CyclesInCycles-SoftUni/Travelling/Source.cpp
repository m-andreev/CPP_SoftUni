#include <iostream>
#include <string>
using namespace std;

int main()
{
	string destination; getline(cin >> ws, destination);

	while (destination != "End")
	{
		double neededMoney; cin >> neededMoney;
		double sum = 0.0;
		double totalSum = 0.0;

		while(totalSum < neededMoney)
		{
			cin >> sum;
			totalSum += sum;
		}
		cout << "Going to " << destination << "!" << endl;
		getline(cin >> ws, destination);
	}
	return 0;
}