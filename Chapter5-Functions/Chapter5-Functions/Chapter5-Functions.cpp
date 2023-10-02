
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

const string ROCK = "rock";
const string PAPER = "paper";
const string SCISSORS = "scissors";


// return type or void, function name, () optional arguments {
void happyMonday() {
    cout << "Happy Monday!" << endl;
    cout << "We need more coffee!" << endl;
}

void happyDay(string day) {
    cout << "Happy "<< day << "!" << endl;
    cout << "We need more coffee!" << endl;
}

void ifYoureHappyAndYouKnowIt(string action, int verseNumber) {
    if (verseNumber < 3) {
        cout << "If you're happy and you know it " << action << endl;
    }
    else {
        cout << "If you're happy and you know it "
            << "and you really want to show it " << action << endl;
    }
}

string getUsersThrow() {
    
    string usersThrow = "";

    while (usersThrow != ROCK and usersThrow != PAPER and
        usersThrow != SCISSORS) {
        cout << "Enter rock, paper, or scissors" << endl;
        cin >> usersThrow;
    }

    return usersThrow;
}

string getComputersThrow() {
    srand(time(0));

    int randomThrow = rand() % 3;
    string computerThrow;

    if (randomThrow == 0) {
        computerThrow = ROCK;
        // return "rock";
    }
    else if (randomThrow == 1) {
        computerThrow = PAPER;
        // return "paper";
    }
    else {
        computerThrow = SCISSORS;
        // return "scissors";
    }

    return computerThrow;

    // we'll never get to this line
    cout << "Function still running??!?" << endl;
}

void displayWinner(string usersThrow, string computersThrow) {
    if (usersThrow == computersThrow) {
        cout << "Draw!" << endl;
    }
    else if (usersThrow == ROCK and computersThrow == SCISSORS
        or usersThrow == PAPER and computersThrow == ROCK
        or usersThrow == SCISSORS and computersThrow == PAPER) {
        cout << "Player wins!" << endl;
    }
    else {
        cout << "Player loses!" << endl;
    }
}

int main()
{
    int number = 42;
    cout << number;

    // order matters in variables AND functions
    // cout << anotherNumber;
    // int anotherNumber = 77;


    happyMonday();
    happyMonday();
    happyMonday();

    happyDay("Monday");

    for (int verse = 1; verse <= 3; verse++) {
        ifYoureHappyAndYouKnowIt("clap your hands", verse);
    }

    cout << "You should buy a lotto ticket with nubmers ";
    for (int number = 0; number < 5; number++) {
        cout << rand() % 69 + 1 << " ";
    }
    cout << "Powerball " << rand() % 26 + 1 << endl;
   
    char playAgain = 'y';
    while (tolower(playAgain) == 'y') {

        // string usersThrow = getUsersThrow();
        // string computersThrow = getComputersThrow();
        // displayWinner(usersThrow, computersThrow);

        displayWinner(getUsersThrow(), getComputersThrow());

        cout << "Do you want to play again? y/n" << endl;
        cin >> playAgain;
    }

    cout << "Pi rounded up with " << ceil(3.14) << endl;

    return 0;
}
