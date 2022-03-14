#include <iostream>
using namespace std;

void evaluation(float m)
{
	if (m >= 2.00 && m < 3.00)
	{
		cout << "Fail" << endl;
	}
	else if (m >= 3.00 && m < 3.50)
	{
		cout << "Poor" << endl;
	}
	else if (m >= 3.50 && m < 4.50)
	{
		cout << "Good" << endl;
	}
	else if (m >= 4.50 && m < 5.50)
	{
		cout << "Very good" << endl;
	}
	else if (m >= 5.50 && m <= 6.00)
	{
		cout << "Excellent" << endl;
	}
}

int main()
{
	float n; cin >> n;
	evaluation(n);

	return 0;
}