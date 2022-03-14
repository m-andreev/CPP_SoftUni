#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int summedNums = 0;
	int secondNum;
	while (num > summedNums)
	{
		cin >> secondNum;
		summedNums += secondNum;
	}
	cout << summedNums << endl;
    
	return 0;
}