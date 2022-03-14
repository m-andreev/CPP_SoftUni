#include <iostream>
using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	if (a * b * c >= 0)
	{
		cout << "+" << endl;
	}
	else
	{
		cout << "-" << endl;
	}

	return 0;
}