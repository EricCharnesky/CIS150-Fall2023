#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int creditsRequiredForDegree;
	int creditsCompleted;

	// use a double so we can get a decimal result later
	double creditsRemaining;
	int averageCreditsPerSemester;
	int totalCost;

	const int COST_PER_CREDIT = 606;
	const int MAX_SEMESTER_COST = 7272;

	cout << "Enter the credits required for your degree" << endl;
	cin >> creditsRequiredForDegree;

	cout << "Enter the credits completed" << endl;
	cin >> creditsCompleted;

	cout << "Enter the average number of credits you take per semester" << endl;
	cin >> averageCreditsPerSemester;

	creditsRemaining = creditsRequiredForDegree - creditsCompleted;

	cout << "You have " << ceil(creditsRemaining / averageCreditsPerSemester)
		<< " semesters left" << endl;

	if (averageCreditsPerSemester < 12) {
		totalCost = creditsRemaining * COST_PER_CREDIT;
	}
	else {
		totalCost = floor(creditsRemaining / averageCreditsPerSemester) * MAX_SEMESTER_COST;
		// lazy approach to get an int for %
		// totalCost = totalCost + (creditsRequiredForDegree - creditsCompleted) % averageCreditsPerSemester * COST_PER_CREDIT;
		totalCost = totalCost + ( static_cast<int>(creditsRemaining) % averageCreditsPerSemester ) * COST_PER_CREDIT;
	}

	cout << "The estimated cost remaining is $" << totalCost << endl;


	return 0;
}