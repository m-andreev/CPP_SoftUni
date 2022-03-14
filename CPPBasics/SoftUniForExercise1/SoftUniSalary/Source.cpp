#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int tabs;
	double salary = 0.0;
	cin >> tabs >> salary;
	string tabName;

	for (size_t col = 1; col <= tabs; col++)
	{
		cin >> tabName;
		if (tabName == "Facebook")
		{
			salary -= 150;
		}
		else if (tabName == "Instagram")
		{
			salary -= 100;
		}
		else if (tabName == "Reddit")
		{
			salary -= 50;
		}

		if (salary <= 0)
		{
			cout << "You have lost your salary." << endl;
			return 0;
		}
	}

	cout << salary << endl;

	return 0;
}