#include <iostream>
using namespace std;

int main()
{
	string name;
	string password;
	cin >> name;
	cin >> password;
	string input;
	cin >> input;

	while (input != password)
	{
		cin >> input;
	}

	if (input == password)
	{
		cout << "Welcome " << name << "!" << endl;
	}
	return 0;
}