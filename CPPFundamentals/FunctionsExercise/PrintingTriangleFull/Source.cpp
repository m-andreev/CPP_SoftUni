#include <iostream>
using namespace std;


void triangle(int number)
{
    for (int i = 1; i <= number - 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << j << " ";
        }
        std::cout << endl;
    }
    for (int a = 1; a <= number; number--)
    {
        for (int b = 1; b <= number; b++)
        {
            cout << b << " ";
        }
        cout << endl;
    }
}


int main()
{
    int number; std::cin >> number;
    triangle(number);

    return 0;
}