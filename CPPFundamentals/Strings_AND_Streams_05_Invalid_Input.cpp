#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string line;
	getline(cin, line);

	istringstream input1(line);

	ostringstream letters;

	string current;
	int sum = 0;
	int index = 0;

	while (input1 >> current)
	{
		char c = current[0]; /// gledame pyrvoto simvolche ot parcheto string , ako to e bukva => otiva v letters
		if (c >= 'a' && c <= 'z' || c>='A' && c<='Z')
		{
			letters << current << " ";
		}
		else
		{
			int n = stoi(current);
			sum += n;
		}
	}
	cout << sum << endl;
	cout << letters.str()<<endl;


	return 0;
}