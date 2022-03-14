#include <iostream>
using namespace std;

void triangleView(int m)
{
	int br = 1;
	for (int i = 1; i <= m; i++)
	{
		int number = 1;
		for (int j = 1; j <= i ; j++)
		{
			cout << number << " ";
			number++;
		}
		
		cout << endl;
	}

	/*if (i == m)
	{
		for (i = m; i >= 1; i--,m++)
		{
			cout << i << " ";
		}
	}*/
}

int main()
{
	int n; cin >> n;
	triangleView(n);

	return 0;
}