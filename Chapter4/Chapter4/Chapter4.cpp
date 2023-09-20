#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

int main() {
	srand(time(0));// more unique looking random value

	int numberToGuess = rand() % 100 + 1; 

	int guess;
	cout << "Guess a number 1-100" << endl;
	std::cin >> guess;

	const int MAX_GUESSES = 10;

	int numberOfGuesses = 1;

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

	// input validation loop
	string input;
	cout << "Enter rock, paper, or scissors" << endl;
	cin >> input;

	while (input != "rock" and input != "paper" and input != "scissors") {
		cout << "invalid entry, please enter rock, paper, or scissors" << endl;
		cin >> input;
	}


	

	return 0;
}