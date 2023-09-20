#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string name;
	cout << "Enter your name" << endl;
	cin >> name;

	
	int numberOfGuests;
	cout << "How many guests are coming to the party" << endl;
	cin >> numberOfGuests;

	const string PIZZA = "1";
	const string SANDWICHES = "2";
	const string DRINKS = "3";

	string food;
	cout << name << ", what kind of food do you want to serve? (1) - pizza, (2) - sandwiches, or (3) - drinks" << endl;
	cin >> food;
	// figure out lower case when eric isn't on meds

	if (food == PIZZA) {
		double averageSlicesPerGuest;
		cout << name << ", Enter the average number of slices a guest will eat" << endl;
		cin >> averageSlicesPerGuest;

		int slicesPerPizza;
		cout << name << ", Enter the number of slices per pizza" << endl;
		cin >> slicesPerPizza;

		double costPerPizza;
		cout << name << ", Enter the cost per pizza" << endl;
		cin >> costPerPizza;

		int guestsActuallyAttended;
		cout << name << ", How many guests actually came?" << endl;
		cin >> guestsActuallyAttended;

		double pizzasNeeded = 
			ceil((numberOfGuests * averageSlicesPerGuest) / slicesPerPizza);

		double totalCost = pizzasNeeded * costPerPizza;

		int leftoverSlices = (pizzasNeeded * slicesPerPizza) -
			(averageSlicesPerGuest * guestsActuallyAttended);

		cout << name << ", You to buy " << pizzasNeeded << " pizzas, for a cost of "
			<< totalCost << " and you'll have " << leftoverSlices << " slices leftover" << endl;

	}
	else if (food == SANDWICHES) {

	}
	else if (food == DRINKS) {

	}
	else {
		cout << "Sorry I can't help plan a party serving " << food << endl;
	}





	return 0;
}