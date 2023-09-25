#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

int main() {

	for (int hour = 0; hour < 24; hour++) {
		for (int minute = 0; minute < 60; minute++) {
			for (int second = 0; second < 60; second++) {
				// https://stackoverflow.com/questions/1714515/how-can-i-pad-an-int-with-leading-zeros-when-using-cout-operator
				cout << setfill('0') << setw(2) << hour << ":" 
					<< setfill('0') << setw(2) << minute << ":" 
					<< setfill('0') << setw(2) << second << endl;
			}
		}
	}

	int rows;
	int columns;

	cout << "Enter the number of rows for a rectangle" << endl;
	cin >> rows;

	cout << "Enter the number of columns for a rectangle" << endl;
	cin >> columns;

	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			cout << "*"; // no endl
		}
		cout << endl;
	}


	srand(time(0));// more unique looking random value

	int numberToGuess = rand() % 100 + 1; 

	int guess;
	cout << "Guess a number 1-100" << endl;
	std::cin >> guess;

	const int MAX_GUESSES = 10;

	int numberOfGuesses = 1;

	char playAgain = 'y';

	while (tolower(playAgain) == 'y') {

		// loop will run if the condition is true
		// pre-test - might not run
		while (guess != numberToGuess && numberOfGuesses < MAX_GUESSES) {
			if (guess < numberToGuess) {
				cout << "too low!" << endl;
			}
			else {
				cout << "too high!" << endl;
			}
			cout << "You have " << MAX_GUESSES - numberOfGuesses << " guesses left!" << endl;
			cout << "Guess again!" << endl;
			std::cin >> guess;
			// slow way
			// numberOfGuesses = numberOfGuesses + 1;

			// combined assignment operator
			numberOfGuesses += 1;

			// this won't do what you think it does
			// setting number of guesses to positive 1
			// numberOfGuesses =+ 1;

			// most common - post incriment
			// numberOfGuesses++;

			// pre-incriment
			// ++numberOfGuesses;
		}



		if (guess == numberToGuess) {
			cout << "You got it in " << numberOfGuesses << " guesses!" << endl;
		}
		else {
			cout << "better luck next time, the number was " << numberToGuess << endl;
		}

		cout << "DO you want to play agin? y/n" << endl;
		cin >> playAgain;
		

	}

	// input validation loop
	string input;
	cout << "Enter rock, paper, or scissors" << endl;
	cin >> input;

	/*while (input != "rock" and input != "paper" and input != "scissors") {
		cout << "invalid entry, please enter rock, paper, or scissors" << endl;
		cin >> input;
	}*/

	// compare first character to character 'r'
	while (tolower(input.at(0)) != 'r' and tolower(input.at(0)) != 'p' and tolower(input.at(0)) != 's') {
		cout << "invalid entry, please enter rock, paper, or scissors" << endl;
		cin >> input;
	}

	int userThrow;
	cout << "Pick one!\n\t1 - Rock\n\t2 - Paper\n\t3 - Scissors" << endl;
	cin >> userThrow;

	// invalid too low or invalid too high
	while (userThrow < 1 or userThrow > 3) {
		cout << "Pick one!\n\t1 - Rock\n\t2 - Paper\n\t3 - Scissors" << endl;
		cin >> userThrow;
	}

	const int ROCK = 1;
	const int PAPER = 2;
	const int SCISSORS = 3;
	
	int computerThrow = rand() % 3 + 1;
	string computerStringThrow;
	if (computerThrow == 1) {
		computerStringThrow = "rock";
	} // ...

	if ( input == "rock" and computerStringThrow == "rock" )

	if (userThrow == computerThrow) {
		cout << "Tie!" << endl;
	}
	else if ((userThrow == ROCK and computerThrow == SCISSORS)
		or (userThrow == PAPER and computerThrow == ROCK)
		or (userThrow == SCISSORS and computerThrow == PAPER)) {
		cout << "Player wins!" << endl;
	}
	else {
		cout << "You lose!" << endl;
	}

	double sum = 0;

	// throw away value to make sure the loop runs
	int recipt = 1;
	int receiptCount = 0;

	// 0 is my sentinel value - a deliberate weird value
	while (recipt != 0) {
		cout << "Enter the receipt amount, or 0 to stop" << endl;
		cin >> recipt;
		sum += recipt;
		if (recipt != 0) {
			receiptCount += 1;
		}
		
	}

	cout << "Your recipt total is " << sum << endl;
	cout << "Your average recipt is " << sum / receiptCount << endl;

	int totalScore = 0;
	// initialize ; test ; update
	for (int score = 1; score <= 10; score++) {
		cout << "Enter score #" << score;
		int input;
		cin >> input;
		totalScore += input;
	}

	// with while
	// int score = 1;
	// while ( score <= 10 ) {
	//		cout << "Enter score #" << score;
	//		int input;
	//		cin >> input;
	//		totalScore += input;
	//		score++;
	// }

	string name;
	cout << "Enter your name" << endl;
	cin >> name;

	for (int index = 0; index < name.size(); index++) {
		name.at(index) = toupper(name.at(index));
	}
	cout << name << endl;

	// infinite loop
	//for (;;) {
	//	cout << "AYYYYYYYY" << endl;
	//}

	// infinite loop
	//while (true) {
	//	cout << "BEEEEEEEEE" << endl;
	//}

	int highestNumber = INT_MIN;
	int number = 1;
	int lowestNumber = INT_MAX;

	while (number != 0) {
		cout << "Enter a number, or 0 to stop" << endl;
		cin >> number;
		if (number > highestNumber) {
			highestNumber = number;
		}
		if (number < lowestNumber) {
			lowestNumber = number;
		}
	}

	cout << "highest number is " << highestNumber;
	cout << "lowest number is " << lowestNumber;

	return 0;
}