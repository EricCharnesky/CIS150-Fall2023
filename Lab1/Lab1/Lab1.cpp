
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;


	const int SQUARE = 1;
	const int RECTANGLE = 2;
	const int RIGHT_TRIANGLE = 3;
	const int EQUILATERAL_TRIANGLE = 4;
	const int DIAMOND = 5;
	const int QUIT = 6;

	// throw away starter value
	int choice = 5;

	while (choice != QUIT) {

		// ask user to pick shape

		cout << "MOAR shapes?!?" << endl;
		cin >> choice;


		if (choice == SQUARE) {
			int rows = 10; // ask the user for this
			int columns = 10;

			for (int row = 0; row < rows; row++)
			{
				for (int column = 0; column < columns; column++) {
					cout << "*";
				}
				cout << endl;
			}
		}

		else if (choice == RIGHT_TRIANGLE) {
			int size = 9;

			for (int row = 1; row <= size; row++) {
				for (int column = 1; column <= row; column++) {
					cout << "*";
				}
				cout << endl;
			}

			for (int row = 1; row <= size; row++) {
				for (int space = 1; space <= size - row; space++) {
					cout << " ";
				}
				for (int column = 1; column <= row; column++) {
					cout << "*";
				}
				cout << endl;
			}
		}

		else if (choice == DIAMOND) {
			int diamondSize = 11;
			int spaces = diamondSize / 2;
			int stars = 1;

			while (stars != diamondSize) {
				for (int space = 0; space < spaces; space++)
				{
					cout << " ";
				}
				for (int star = 0; star < stars; star++) {
					cout << "*";
				}
				cout << endl;
				stars += 2;
				spaces -= 1;
			}

			while (stars >= 1) {
				for (int space = 0; space < spaces; space++)
				{
					cout << " ";
				}
				for (int star = 0; star < stars; star++) {
					cout << "*";
				}
				cout << endl;
				stars -= 2;
				spaces += 1;
			}
		}



	}


    
}
