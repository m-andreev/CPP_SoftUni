#include <iostream>
#include <string>
#include <iomanip>
#include <climits>
using namespace std;

int main()
{
	string input;
	double totalSum = 0.0;
	cout.setf(ios::fixed);
	cout.precision(2);

	for (size_t i = 1; i <= 3; i++)
	{
		cin >> input;
		if (input == "NoMoreMoney")
		{
			cout << "Total: " << totalSum << endl;
			return 0;
		}
		double input2 = stod(input);
		if (input2<0)
		{
			cout << "Invalid operation!" << endl;
			cout << "Total: " << totalSum << endl;
			return 0;
		}
		else if (input2 >= 0)
		{
			cout << "Increase: " << input2 << endl;
			totalSum += input2;
		}
		if (i == 3)
		{
			cout << "Total: " << totalSum << endl;
		}
	}
	return 0;
}