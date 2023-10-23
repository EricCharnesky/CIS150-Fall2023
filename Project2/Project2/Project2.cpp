
#include <iostream>
#include <string>

using namespace std;

string get_word() {
    // TODO - FIXME
    return "test";
}

bool has_the_word_been_guessed(string hidden_word, string letters_guessed) {
    // for every letter in the hidden word
    // check every letter in the letters guessed
    // if it's not there, return false

    // at the end, if you haven't returned false, return true
    return false;
}

bool has_person_been_hanged(int number_of_incorrect_guesses) {
    return false;
}

void display_hidden_word(string hidden_word, string letters_guessed) {
    // for every letterin the hidden word, if it's been guessed, print the letter
    // if it hasn't been guessed, print "_"
    // for every letter in hidden word
    // { 
      // for every letter in letters gussed
        // { 
        //   if the letter matches
          //   mark that it has been matched
        // }
       // if the letter matched, print letter
       // otherwise print "_"
     // }
}

char get_letter_guess(string letters_guessed) {
    // get a guess, make sure it's 1 letter
    // make sure it's not in the letters_guessed
    return 'a';
}

bool is_letter_guessed_is_in_hidden_word(char letter_guessed, string hidden_word) {
    // check every letter in hidden word to see if it matches letter_guessed
    // for every letter in hidden_word
    // {
       // if you find it, return true
    // }
    // if we haven't returned true, we can return false
    return false;
}

void print_gallows(int number_of_incorrect_guesses) {

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
