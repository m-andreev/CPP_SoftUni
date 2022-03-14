#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string movieName = "";
	string typeOfTicket = " ";
	int freeSeats;

	int ticketCounter=0;
	int totalTicketCounter = 0;
	int standardCounter = 0;
	int studentCounter = 0;
	int kidCounter = 0;
	
	
	double standardPercentage = 0.0;
	double studentPercentage = 0.0;
	double kidPercentage = 0.0;
	double occupiedSpace = 0.0;

	while (movieName != "Finish")
	{
		getline(cin >> ws, movieName);
		if (movieName == "Finish")
		{
			break;
		}
		cin >> freeSeats;
		ticketCounter = 0;
		typeOfTicket = "";
		while (typeOfTicket != "End"&& movieName!="Finish")
		{
			for (int i = 0; i < freeSeats; i++)
			{
				cin >> typeOfTicket;
				if (typeOfTicket == "End")
				{
					break;
				}
				ticketCounter++;
				totalTicketCounter++;

				if (typeOfTicket == "standard")
				{
					standardCounter++;
				}
				else if (typeOfTicket == "student")
				{
					studentCounter++;
				}
				else if (typeOfTicket == "kid")
				{
					kidCounter++;
				}
			}
				if (ticketCounter == freeSeats || typeOfTicket == "End")
				{
					occupiedSpace = (double)(ticketCounter * 100) / freeSeats;
					cout << movieName << " - " << fixed << setprecision(2) << occupiedSpace << "% full." << endl;
					break;
				}
		}
	}
	standardPercentage = (standardCounter*100.00) / totalTicketCounter;
	studentPercentage = (studentCounter*100.00 )/ totalTicketCounter;
	kidPercentage = (kidCounter *100.00)/ totalTicketCounter;
	
	cout << "Total tickets: " << totalTicketCounter << endl;
	cout <<fixed<<setprecision(2) << studentPercentage << "% student tickets." << endl;
	cout << fixed << setprecision(2) << standardPercentage << "% standard tickets." << endl;
	cout << fixed << setprecision(2) << kidPercentage << "% kids tickets." << endl;

	return 0;
}