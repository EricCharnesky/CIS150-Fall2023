#include <iostream>
#include <string>

using namespace std;

int main() {

	cout << "Enter a value for the weather today" << endl;
	cout << "1 - Sunny and hot" << endl;
	cout << "2 - Cloudy and mild" << endl;
	cout << "3 - Rainy" << endl;

	int weatherInput;
	cin >> weatherInput;

	if (weatherInput == 1) {
		cout << "Bring some sunscreen" << endl;
		cout << "Drink lots of water" << endl;
	}
	else if (weatherInput == 2) {
		cout << "Say goodbye to summer" << endl;
	}
	else if (weatherInput == 3) {
		cout << "Bring your umbrella" << endl;
	}
	else
	{
		cout << "I don't understand, I said enter 1, 2, or 3";
	}

	cout << "Enter your percentage grade like 0-100" << endl;
	double score;

	cin >> score;

	// mutally exclusive, the first to match runs
	if (score >= 93.5 ) {
		cout << "A" << endl;
	}
	else if (score >= 89.5) {
		cout << "A-" << endl;
	}
	else if (score >= 86.5) {
		cout << "B+" << endl;
	}
	else if (score >= 83.5) {
		cout << "B" << endl;
	}
	else if (score >= 79.5) {
		cout << "B-" << endl;
	}
	// ....
	else {
		cout << "F" << endl;
	}

	cout << "Enter your name" << endl;
	string name;
	cin >> name;

	// case matters with strings
	if (name == "Eric") {
		cout << "You win! " << name << endl;
	}

	cout << "Enter your age" << endl;
	int age;
	cin >> age;

	cout << "Enter your gender M/F" << endl;
	string gender;
	cin >> gender;

	if (age < 21) {
		cout << "Your insurance costs $200/month" << endl;
	}
	// and &&
	else if (age < 28 and gender == "M") {
		cout << "Your insurance costs $180/month" << endl;
	}
	else {
		cout << "Your insurance costs $100/month" << endl;
	}

/*
	logical operators
	
	AND &&
	true and true == true
	true and false == false
	false and true == false
	false and false == false

	OR ||
	true or true == true
	true or false == true
	false or true == true
	false or false == false

	NOT !
	!true == false
	!false == true
*/


	cout << "How much does the house you want to buy cost?" << endl;
	int houseCost;
	cin >> houseCost;

	cout << "How much money do you have for a down payment?" << endl;
	double downPayment;
	cin >> downPayment;
	cout << "downPayment / houseCost: " << downPayment / houseCost << endl;

	// if you divide integer by integer, you get integer results
	if (downPayment / houseCost >= .2) {
		cout << "You get a mortage! (15 year)" << endl;
	}
	else {
		cout << "That down payment isn't large enough to qualify, enter your credit score" << endl;
		int creditScore;
		cin >> creditScore;

		if ( (downPayment / houseCost >= .1 and creditScore > 700)
			or (downPayment / houseCost >= .05 and creditScore > 750)) {
			cout << "You get a mortgage!" << endl;
		}
		else {
			cout << "No mortgage for you!" << endl;
		}
	}


	return 0;
}