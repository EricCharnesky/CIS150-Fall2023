
#include <iostream>
#include <string>

using namespace std;

string get_word() {
	string word = "";
	while (word.size() < 4) {
		cout << "Enter a word to guess ( at least 4 letters long )" << endl;
		cin >> word;
	}
	return word;
}

bool has_person_been_hanged(int number_of_incorrect_guesses) {
	return number_of_incorrect_guesses == 6;
}

bool is_letter_guessed_is_in_hidden_word(char letter_guessed, string hidden_word) {
	for (int index = 0; index < hidden_word.size(); index++) {
		if (letter_guessed == hidden_word.at(index)) {
			return true;
		}	
	}
	return false;
}

bool has_the_word_been_guessed(string hidden_word, string letters_guessed) {
	for (int index = 0; index < hidden_word.size(); index++) {
		if (!is_letter_guessed_is_in_hidden_word(hidden_word.at(index), letters_guessed)) {
			return false;
		}
	}
	return true;
}

void display_hidden_word(string hidden_word, string letters_guessed) {
	for (int index = 0; index < hidden_word.size(); index++) {
		if (is_letter_guessed_is_in_hidden_word(hidden_word.at(index), letters_guessed)) {
			cout << hidden_word.at(index);
		}
		else {
			cout << "_";
		}
	}
}

char get_letter_guess(string letters_guessed) {
	cout << "Enter a letter to guess" << endl;
	string input;
	cin >> input;

	while (input.size() != 1 or
		is_letter_guessed_is_in_hidden_word(input.at(0), letters_guessed))
	{
		if (input.size() != 1) {
			cout << "Enter only 1 letter a time please" << endl;
		}
		if (is_letter_guessed_is_in_hidden_word(input.at(0), letters_guessed)) {
			cout << "You already guessed that" << endl;
		}
		cout << "Enter a letter to guess" << endl;
		cin >> input;
	}
	return input.at(0);
}

void print_gallows(int number_of_incorrect_guesses) {
	if (number_of_incorrect_guesses == 0) {
		// print without the body
	}
	cout <<
		"| ---- -" << endl <<
		"|    |" << endl <<
		"|    O" << endl <<
		"| -- | --" << endl <<
		"|   / \\" << endl <<
		"|" << endl <<
		"-----------" << endl;
}


int main()
{
	string letters_guessed = "";
	string hidden_word = get_word();
	int number_of_incorrect_guesses = 0;

	while (!has_the_word_been_guessed(hidden_word, letters_guessed)
		and !has_person_been_hanged(number_of_incorrect_guesses)) {
		display_hidden_word(hidden_word, letters_guessed);
		char guess = get_letter_guess(letters_guessed);
		// either add the letter or update the letters_guessed in the fuction
		letters_guessed += guess;

		// check if the letter guessed is in the hidden word or not
		if (!is_letter_guessed_is_in_hidden_word(guess, hidden_word)) {
			number_of_incorrect_guesses += 1;
		}

		print_gallows(number_of_incorrect_guesses);
	}
	cout << "The word was: " << hidden_word << endl;
}