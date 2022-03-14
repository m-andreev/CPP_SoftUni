#include <iostream>
using namespace std;

int main()
{
	int number1; cin >> number1;
	int number2; cin >> number2;


	for (int number = number1; number <= number2; number++)
	{
		
		//////// 562341 ---> 6;3;1 - edinici + stotici + desetohilqdni
		//////// 562341 ---> 5;2;4 - desetici + hilqdni + stohilqdni
		
		int units = number % 10 ;
		int tens = number/10 % 10;
		int hundreds = number/100 % 10;
		int thousands = number/1000 % 10;
		int tenThousands = number/10000 % 10;
		int hundredThousands = number/100000;


		int sumEven = units + hundreds + tenThousands;
		int sumOdd = tens + thousands + hundredThousands;

		if (sumEven == sumOdd)
		{
			cout << number << " ";
		}
	}
	return 0;
}