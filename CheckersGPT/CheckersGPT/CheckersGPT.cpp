// https://umgpt.umich.edu/
// prompt "write a c++ program that lets a user play checkers again another player"

#include <iostream>
using namespace std;

const int BOARD_SIZE = 8;
char board[BOARD_SIZE][BOARD_SIZE];
char player1[] = ("X");
char player2[] = ("O");

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void movePiece(int oldX, int oldY, int newX, int newY) {
    char temp = board[oldX][oldY];
    board[oldX][oldY] = ' ';
    board[newX][newY] = temp;
}

int main() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j += 2) {
            board[i][j] = i % 2 == 0 ? player1 : player2;
            board[i][j + 1] = i % 2 == 0 ? player2 : player1;
        }
    }
    printBoard(board);
    int oldX, oldY, newX, newY;
    while (true) {
        cout << "Enter the coordinates of the piece you want to move in the format X Y (0-indexed): ";
        cin >> oldX >> oldY;
        cout << "Enter the desired coordinates in the format X Y: ";
        cin >> newX >> newY;
        movePiece(oldX, oldY, newX, newY);
        printBoard(board);
    }
    return 0;
}