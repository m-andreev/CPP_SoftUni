#include <iostream>
using namespace std;

int main()
{
	int peopleInGroup; cin >> peopleInGroup;
	int numOfStays; cin >> numOfStays;
	int transportCards; cin >> transportCards;
	int museumTickets; cin >> museumTickets;

	double nightsPrice = numOfStays * 20.00;
	double cardsTransportPrice = transportCards * 1.60;
	double ticketsMuseumPrice = museumTickets * 6.00;

	double pricePerGuy = nightsPrice + cardsTransportPrice + ticketsMuseumPrice;
	double priceForWholeGroup = pricePerGuy * peopleInGroup;

	double totalSum = (double)priceForWholeGroup + (priceForWholeGroup * 0.25);

	cout.setf(ios::fixed);
	cout.precision(2);
	cout << totalSum << endl;

	return 0;
}