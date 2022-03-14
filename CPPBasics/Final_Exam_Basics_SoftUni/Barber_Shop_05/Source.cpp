#include <iostream>
#include <string>
using namespace std;

int main()
{
	int target; cin >> target;
	int money = 0;
	string command = "";
	string command2 = "";

	while (command != "closed")
	{
		getline(cin >> ws,command);
		if(command == "haircut")
		{
			getline(cin >> ws,command2);
			if (command2 == "mens")
			{
				money += 15;
			}
			if (command2 == "ladies")
			{
				money += 20;
			}
			if (command2 == "kids")
			{
				money += 10;
			}
		}
		if (command == "color")
		{
			getline(cin >>ws, command2);
			if (command2 == "touch up")
			{
				money += 20;
			}
			if (command2 == "full color")
			{
				money += 30;
			}
		}
		if (command == "closed"||money>=target)
		{
			break;
		}
	}
	if (money >= target)
	{
		cout << "You have reached your target for the day!" << endl;
		cout << "Earned money: " << money << "lv." << endl;
	}
	else
	{
		cout << "Target not reached! You need " << target - money << "lv. more." << endl;
		cout << "Earned money: " << money << "lv."<<endl;
	}

	return 0;
}