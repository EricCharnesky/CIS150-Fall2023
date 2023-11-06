// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int main() {

	int count_greater_than_80 = 0;

	int score;

	for (int i = 0; i < 10; i++) {

		printf("Enter score %d (0-100): ", i + 1);

		if (scanf_s("%d", &score) == 1) {

			if (score >= 0 && score <= 100) {

				if (score > 80) {

					count_greater_than_80++;

				}

			}
			else {

				printf("Invalid input. Score must be between 0 and 100.\n");

			}

		}
		else {

			printf("Invalid input. Please enter a valid integer.\n");

			while (getchar() != '\n'); // Clear input buffer

		}

	} printf("Number of scores greater than 80: %d\n", count_greater_than_80);

	return 0;

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
