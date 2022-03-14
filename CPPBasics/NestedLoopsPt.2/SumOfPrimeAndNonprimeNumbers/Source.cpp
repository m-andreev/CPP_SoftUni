#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	cin >> input;

	int sumPrime = 0;
	int sumNonPrime = 0;

	while (input != "stop")
	{
		int number = stoi(input);
		if (number < 0)
		{
			cout << "Number is negative." << endl;
		}
		else
		{
			int divider = 0;

			for (int i = 1; i <= number; i++)
			{
				if (number % i == 0)
				{
					divider++;
				}
			}

			if (divider == 2)
			{
				sumPrime += number;
			}
			else
			{
				sumNonPrime += number;
			}
		}
		cin >> input;
	}
	cout << "Sum of all prime numbers is: " << sumPrime << endl;
	cout << "Sum of all non prime numbers is: " << sumNonPrime << endl;
	return 0;
}


    //povtarqm : vyvejdam vhodni danni
	//vhodni danni : stop ili chislo pod formata na tekst
	//spiram : vhodni danni == "stop"
	//prodyljavam : vhodni danni != "stop"