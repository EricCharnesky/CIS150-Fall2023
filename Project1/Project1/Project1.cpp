#include <iostream>
#include <ctime>
#include "Project1.h"

using namespace std;

const string X_PLUS = "x+";
const string X_MINUS = "x-";
const string Y_PLUS = "y+";
const string Y_MINUS = "y-";
const string THRUSTERS = "thrusters";
const string SELF_DESTRUCT = "selfDestruct";
const string NOTHING = "nothing";

int getRandomValueNegativeTentoTen() {
	return rand() % 21 - 10;
}

string getValidCommand() {
	string command = "";

	while (command != X_PLUS and command != X_MINUS
		and command != Y_PLUS and command != Y_MINUS
		and command != THRUSTERS and command != SELF_DESTRUCT
		and command != NOTHING) {
		cout << "Please enter x+ , x- , y+ , y- , thrusters, selfDestruct, nothing" << endl;
		cin >> command;
	}

	return command;

}

void selfDestruct() {
	string cancellationCode = "";
	while (cancellationCode != "STOP") {
		cout << "Self destruct sequence activated: enter cancellation code:" << endl;
		cin >> cancellationCode;
	}
	cout << "Self destruct aborted" << endl;
}

void displayStatus(int distanceFromSurface, int xTilt, int yTilt)
{
	cout << "You are " << distanceFromSurface << " units from the surface" << endl;
	cout << "Your x tilt is " << xTilt << " and your y tilt is " << yTilt << endl;
}

void displayCrashOrLand(int xTilt, int yTilt)
{
	if (xTilt == 0 and yTilt == 0) {
		cout << "You landed successfully!" << endl;
	}
	else {
		cout << "You crashed the 3 billion dollar lander, uh oh!" << endl;
	}
}

void getLanderToSurface(int& xTilt, int& yTilt) {
	int distanceFromSurface = 10;

	while (distanceFromSurface > 0) {
		displayStatus(distanceFromSurface, xTilt, yTilt);

		string command = getValidCommand();

		if (command == X_PLUS) {
			xTilt++;
		}
		else if (command == X_MINUS) {
			xTilt--;
		}
		else if (command == Y_PLUS) {
			yTilt++;
		}
		else if (command == Y_MINUS) {
			yTilt--;
		}
		else if (command == THRUSTERS) {
			distanceFromSurface += 2;
		}
		else if (command == SELF_DESTRUCT) {
			selfDestruct();
		}

		distanceFromSurface--;
	}

	displayCrashOrLand(xTilt, yTilt);
}

int main()
{
	srand(time(0));
	string playAgain = "y";

	while (playAgain == "y") {
		int xTilt = getRandomValueNegativeTentoTen();
		int yTilt = getRandomValueNegativeTentoTen();

		getLanderToSurface(xTilt, yTilt);

		cout << "Do you want to play again? y/n" << endl;
		cin >> playAgain;
	}

	return 0;
}
