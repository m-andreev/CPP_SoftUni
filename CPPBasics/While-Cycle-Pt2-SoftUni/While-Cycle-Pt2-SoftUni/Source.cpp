#include <iostream>
#include <string>
using namespace std;

int main()
{
    string aniBook; getline(cin >> ws, aniBook);
    bool is_found = false;
    int count = 0;

    while (!is_found)
    {
        string book; getline(cin >> ws, book);
        count++;

        if (book == aniBook)
        {
            count--;
            cout << "You checked " << count << " books and found it." << endl;
            return 0;
        }
        else if (book == "No More Books")
        {
            count--;
            cout << "The book you search is not here!" << endl;
            cout << "You checked " << count << " books." << endl;
            return 0;
        }
    }
}