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

	cout << "Enter your year in school (1-4)" << endl;
	int yearInSchool;
	cin >> yearInSchool;

	switch (yearInSchool) {
	case 1:
		cout << "Freshman" << endl;
		break;
	case 2:
		cout << "Sophomore" << endl;
		break;
	case 3:
		cout << "Junior" << endl;
		break;
	case 4:
		cout << "Senior" << endl;
		break;
	default:
		cout << "unknown year" << endl;
	}

	if (yearInSchool == 1) {
		cout << "Freshman" << endl;
	}
	else if (yearInSchool == 2) {
		cout << "Sophomore" << endl;
	}
	else if (yearInSchool == 3) {
		cout << "Junior" << endl;
	}
	else if (yearInSchool == 4) {
		cout << "Senior" << endl;
	}
	else {
		cout << "unknown year" << endl;
	}

	cout << "Are you going to a party tonight?" << endl;
	string answer;
	cin >> answer;

	bool partyOn;

	if (answer == "Y" or answer == "y") {
		partyOn = true;
	}
	else {
		partyOn = false;
	}

	// compare just the first letter as upper case
	if ( toupper(answer.at(0)) == 'Y' )

	// same as above, but in 1 line because we're cool
	partyOn = (answer == "Y" or answer == "y");


	// don't use if ( partyOn == true )
	if (partyOn) {
		cout << "Have fun!" << endl;
	}

	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << alphabet.at(4);
	cout << alphabet.at(17);
	cout << alphabet.at(8);
	cout << alphabet.at(2);
	cout << endl;

	cout << "What letter index should we replace (0-25)" << endl;
	int index;
	cin >> index;
	// assign indiviaul characters with ' ' , not " " 
	alphabet.at(index) = '_';

	cout << alphabet;

	// THIS WILL CRASH! there is no index 4
	// string myName = "Eric";
	// cout << myName.at(4) << endl;

	cout << "Enter your email address" << endl;
	string email;
	cin >> email;

	if (email.find('@') == string::npos) {
		cout << "That's not a valid email" << endl;
	}
	else {
		cout << "Username is: " << email.substr(0, email.find('@')) << endl;
		// size is length of the string, minus the username length, minus the at sign length
		cout << "Domain is: " << email.substr(email.find('@') + 1, email.size() - email.find('@') - 1) << endl;
	}

	cout << "Are you tired?" << endl;
	cin >> answer;
	
	string needsMoreCoffee;

	if (answer == "yes") {
		needsMoreCoffee = "of course";
	}
	else {
		needsMoreCoffee = "it couldn't hurt";
	}

	// the same as above
	needsMoreCoffee = answer == "yes" ? "of course" : "it couldn't hurt";


	// really bad at percise floating point numbers - use deltas
	if (1.0 / 3 == .3333333333) {
		cout << "one third!" << endl;
	}
	else {
		cout << "not a third?!?!" << endl;
	}


	return 0;
}