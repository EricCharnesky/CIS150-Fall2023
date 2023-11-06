
#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long sumOfVectorValues(vector<int> &numbers) {
    long long sum = 0;
    
    for (int index = 0; index < numbers.size(); index++) {
        sum += numbers.at(index);
        numbers.at(index)--;
    }

    return sum;
}

int sumOfValues(int numbers[], int numberOfValues) {
    //int numberOfValues = sizeof(numbers) / sizeof(numbers[0]);

    int sum = 0;

    for (int index = 0; index < numberOfValues; index++) {
        sum += numbers[index];
    }

    return sum;
}

bool isGameTied(vector<vector<char>> const& board) {
    for (int rowIndex = 0; rowIndex < board.size(); rowIndex++) {
        for (int columnIndex = 0; columnIndex < board.at(rowIndex).size(); columnIndex++) {
            if (board.at(rowIndex).at(columnIndex) == ' ') {
                return false;
            }
        }
    }
    return true;
    
    for (vector<char> row : board) {
        for (char column : row) {
            if (column == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool threeInARowDiagonally(vector<vector<char>> const& board) {
    return board.at(1).at(1) != ' ' and
        ( (board.at(1).at(1) == board.at(0).at(0) and
        board.at(1).at(1) == board.at(2).at(2) ) or
        (board.at(1).at(1) == board.at(2).at(0) and
        board.at(1).at(1) == board.at(0).at(2)));

}

bool threeInARowVertically(vector<vector<char>> const& board) {
    for (int columnIndex = 0; columnIndex < board.size(); columnIndex++) {
        if (board.at(0).at(columnIndex) != ' ' and
            board.at(0).at(columnIndex) == board.at(1).at(columnIndex) and
            board.at(0).at(columnIndex) == board.at(2).at(columnIndex))
        {
            return true;
        }
    }
    return false;
}

bool threeInARowHoriztonally(vector<vector<char>> const& board) {
    for (vector<char> row : board) {
        if (row.at(0) != ' ' and row.at(0) == row.at(1) and row.at(0) == row.at(2)) {
            return true;
        }
    }
    return false;
}

bool threeInARow(vector<vector<char>> const& board) {
    return threeInARowHoriztonally(board) || threeInARowVertically(board)
        || threeInARowDiagonally(board);
}

bool isGameOver(vector<vector<char>> const &board) {
    return isGameTied(board) || threeInARow(board);
}

void printBoard(vector<vector<char>>& board) {
    cout << board.at(0).at(0) << "|" << board.at(0).at(1) << "|" << board.at(0).at(2) << endl;
    cout << "-----" << endl;
    cout << board.at(1).at(0) << "|" << board.at(1).at(1) << "|" << board.at(1).at(2) << endl;
    cout << "-----" << endl;
    cout << board.at(2).at(0) << "|" << board.at(2).at(1) << "|" << board.at(2).at(2) << endl;
}

void makeMove(char currentPlayer, vector<vector<char>> &board) {
    printBoard(board);
    cout << currentPlayer << "'s turn, please enter your row and column index to mark" << endl;
    int rowIndex;
    int columnIndex;
    cin >> rowIndex >> columnIndex;

    while (rowIndex < 0 || rowIndex > 2
        || columnIndex < 0 || columnIndex > 2
        || board.at(rowIndex).at(columnIndex) != ' ') {
        cout << "Invalid location, please enter your row and column index to mark" << endl;
        cin >> rowIndex >> columnIndex;
    }

    board.at(rowIndex).at(columnIndex) = currentPlayer;
}

int main()
{
    vector<vector<char>> board(3);
    for (int row = 0; row < 3; row++) {
        board.at(row) = vector<char>(3);
        for (int column = 0; column < 3; column++) {
            board.at(row).at(column) = ' ';
        }
    }

    vector<vector<char>> easyBoard = {
        { ' ', ' ', ' '},
        { ' ', ' ', ' '},
        { ' ', ' ', ' '}
    };

    char currentPlayer = 'X';

    // while not game over
        // get a move
        // next player

    while (!isGameOver(board)) {
        makeMove(currentPlayer, board);
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        }
        else {
            currentPlayer = 'X';
        }
    }
    
    printBoard(board);
    cout << "Game over!" << endl;
    



    vector<int> randomNumbers(1000000);
    for (int index = 0; index < randomNumbers.size(); index++) {
        randomNumbers.at(index) = rand();
    }


    cout << "The sum of a bunch of random numbers is: " << sumOfVectorValues(randomNumbers) << endl;

    char jeb[4];
    jeb[0] = 'J';
    jeb[1] = 'e';
    jeb[2] = 'b';
    //jeb[3] = '\0';

    char name[15];
    name[0] = 'E';
    name[1] = 'r';
    name[2] = 'i';
    name[3] = 'c';
    name[4] = '\0';

   


    cout << name << endl;
    cout << jeb << endl;

    const int MY_NUMBERS_SIZE = 6;
    // [ ] are for arrays
    int myNumbers[MY_NUMBERS_SIZE];

    myNumbers[0] = 7;
    myNumbers[1] = 13;
    myNumbers[2] = 21;
    myNumbers[3] = 9;
    myNumbers[4] = 5;
    myNumbers[5] = 15;

    cout << "The sum of values in myNumbers: " << sumOfValues(myNumbers, 7) << endl;
    
    int sizeOfMyNumbers = sizeof(myNumbers);
    int sizeOfSingleValue = sizeof(myNumbers[0]);

    int numberOfValuesInMyNumbers = sizeOfMyNumbers / sizeOfSingleValue;

    int sum = 0;
    for (int index = 0; index < MY_NUMBERS_SIZE; index++) {
        sum += myNumbers[index];
    }

    cout << "Sum of array values: " << sum << endl;

    // to make a copy, create at the right size
    int myOtherNumbers[6];

    // copy each value
    for (int index = 0; index < MY_NUMBERS_SIZE; index++) {
        myOtherNumbers[index] = myNumbers[index];
    } 

    vector<int> lottoTicket(6); // creates a vector of 6 0s
    lottoTicket.at(0) = 1;
    lottoTicket.at(1) = 3;
    lottoTicket.at(2) = 5;
    lottoTicket.at(3) = 7;
    lottoTicket.at(4) = 9;
    lottoTicket.at(5) = 11;

    cout << "Sum of values in lotto ticket vector:  " << sumOfVectorValues(lottoTicket) << endl;

    // fails unless to presize the vector
    vector<int> randomTicket;

    // make copies with vectors
    randomTicket = lottoTicket;

    for (int number = 0; number < 5; number++) {
        randomTicket.at(number) = (rand() % 69 + 1);
    }
    randomTicket.at(5) = (rand() % 26 + 1);

    /*for (int number = 0; number < 5; number++) {
        randomTicket.push_back(rand() % 69 + 1);
    }*/
    
    randomTicket.push_back(rand() % 26 + 1);

    cout << "Your easy pick numbers are: "
        << randomTicket.at(0) << " "
        << randomTicket.at(1) << " "
        << randomTicket.at(2) << " "
        << randomTicket.at(3) << " "
        << randomTicket.at(4) << " "
        << randomTicket.at(5) << endl;

    

    for (int number : lottoTicket) {
        cout << number << endl;
    }

    vector<int> numbers;

    //numbers.push_back(1);
    //numbers.push_back(2);
    //numbers.push_back(3);
    //numbers.push_back(4);
    //numbers.push_back(5);
    
    //cout << numbers.at(0) << endl; // first value

    for (int index = 0; index < numbers.size(); index++) {
        cout << numbers.at(index) << endl;
    }

    cout << "Enter a test score or -1 to stop" << endl;
    int score;
    cin >> score;

    while (score != -1) {
        numbers.push_back(score);
        cout << "Enter a test score or -1 to stop" << endl;
        cin >> score;
    }

    double total = 0;

    // range based for loop - enhanced for loop
    // loops for each value in the vector, assigning it to the varaible on the left
    for (int value : numbers) {
        total += value;
    }

    double average = total / numbers.size();

    int maxScore = INT_MIN;

    for (int index = 0; index < numbers.size(); index++) {
        if (numbers.at(index) > maxScore) {
            maxScore = numbers.at(index);
        }
    }

    // read only
    for (int score : numbers) {
        if (score > maxScore) {
            maxScore = score;
        }
    }

    cout << "Average score: " << total / numbers.size() << endl;

    // score is a copy of the value from numbers
    for (int score : numbers) {
        score += (100 - maxScore);
    }

    for (int index = 0; index < numbers.size(); index++) {
        numbers.at(index) += (100 - maxScore);
    }

    total = 0;
    for (int value : numbers) {
        total += value;
    }

    cout << "new Average score: " << total / numbers.size() << endl;


    vector<int> quantities;
    vector<string> items;
    vector<double> prices;

    string item = "";
    int quantity = 0;
    double price = 0;

    while (item != "STOP") {
        cout << "Enter the name of an item to buy or STOP" << endl;
        cin >> item;
        cout << "Enter the quantity" << endl;
        cin >> quantity;
        cout << "Enter the price" << endl;
        cin >> price;
        if (item != "STOP") {
            items.push_back(item);
            prices.push_back(price);
            quantities.push_back(quantity);
        }
    }


    
}
