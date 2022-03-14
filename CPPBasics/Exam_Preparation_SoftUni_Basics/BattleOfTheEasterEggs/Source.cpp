#include <iostream>
#include <string>
using namespace std;

int main()
{
	int eggsP1; cin >> eggsP1;
	int eggsP2; cin >> eggsP2;

	string command = "";

	while (eggsP1!=0||eggsP2 != 0||command != "End of battle")
	{
		getline(cin >>ws, command);
		if (command == "one")
		{
			eggsP2--;
		}
		else if (command == "two")
		{
			eggsP1--;
		}
		if ((eggsP1 == 0) || (eggsP2 == 0) || (command == "End of battle"))
		{
			break;
		}
	}
	if (eggsP1 == 0)
	{
		cout << "Player one is out of eggs. Player two has " << eggsP2 << " eggs left." << endl;
	}
	if (eggsP2 == 0)
	{
		cout << "Player two is out of eggs. Player one has " << eggsP1 << " eggs left." << endl;
	}
	if (command == "End of battle")
	{
		cout << "Player one has " << eggsP1 << " eggs left." << endl;
		cout << "Player two has " << eggsP2 << " eggs left." << endl;
	}

	return 0;
}