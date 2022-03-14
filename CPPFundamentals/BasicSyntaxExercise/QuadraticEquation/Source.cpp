#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a, b, c;
	float x1, x2, D;
	cin >> a >> b >> c;

	///double func = a * pow(x, 2) + b * x + c;
	D = b*b - (4 * a * c);
	
	if (D == 0)
	{
		x1 = -b / (2 * a);
		cout << x1 << endl;
	}
	else if (D > 0)
	{
		x1 = (-b + sqrt(D)) /( 2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		cout << x1 << " " << x2 << endl;
	}
	else
	{
		cout << "no roots" << endl;
	}

	return 0;
}