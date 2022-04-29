#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//Not working properly!!!

string generateSomeJunk()
{
	int junkSize = rand() % 5; ///0...4

	string strJib;

	while(junkSize)
	{
		char c = rand() % (128 - ' ') + ' '; /// (randSymbol % (128-32)) + 32

		if (c == '.' || (c >= '0' && c <= '9'))
		{
			continue; /// This "continue" operator directly bring us back in the beginning of the while cycle
		}

		strJib += c;
		junkSize--;
	}
	return strJib;
}

int main()
{
	srand(time(NULL)); // Initialize our random number generator

	int number = rand() % 46340 + 1; /// 1... 46340

	int numberSquare = number * number; //this number must be embedded in the string

	string strResult = ".";

	while (numberSquare)
	{
		strResult += generateSomeJunk() + strResult;

		int ones = numberSquare % 10;
		//result = string(char(ones + '0'),1) + result; // ti si string ot 1 char , koito = (ones + 48) , dyljinata = 1;
		char str[2];
		str[0] = ones + '0';
		str[1] = '\0';
	
		strResult = str + strResult;

		numberSquare /= 10;
	}

	strResult = generateSomeJunk() + strResult; 
	cout << "The number is : " <<number*number<<" , which is square of "<<number<<" ."<<endl;
	cout << strResult << endl;
	

	//46340 ^ 2 = Last number capable to get in INT_MAX
	//cout << INT_MAX << endl;

	return 0;
}