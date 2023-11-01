
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double fib(int nth) {

	if (nth <= 0) {
		return 0;
	}

	vector<double> numbers;

	numbers.push_back(1);
	numbers.push_back(1);

	for (int n = 2; n < nth; n++) {
		numbers.push_back(numbers.at(n - 1) + numbers.at(n - 2));
	}

	return numbers.at(nth - 1);
}

double geometricSum(double cooefficient, double ratio, int numberOfValues, vector<double> &series) {

	for (int exponent = 0; exponent < numberOfValues; exponent++) {
		series.push_back(cooefficient * pow(ratio, exponent));
	}

	double sum = 0;
	for (double value : series) {
		sum += value;
	}

	return sum;
}

int main()
{
	double cooeficient;
	double ratio = -1;
	int numberOfTerms;

	cout << "Enter a cooeficient" << endl;
	cin >> cooeficient;

	while (ratio <= -1 or ratio >= 1) {
		cout << "Enter a ratio from -1 to 1, exclusive" << endl;
		cin >> ratio;
	}

	cout << "Enter a number of terms" << endl;
	cin >> numberOfTerms;
	
	vector<double> series;

	
	cout << "Terms: " << numberOfTerms << " - Sum: " << geometricSum(cooeficient, ratio, numberOfTerms, series) << endl;
	cout << fixed << setprecision(100);
	for (int index = 0; index < series.size(); index++ ) {
		cout << index << ": " << series.at(index) << endl;
   }
	cout << setprecision(0);

	for (int nth = 1; nth < 50; nth++) {
		cout << nth << ": " << fib(nth) << endl;
	}

	vector<string> affirmations(5);

	affirmations.at(0) = "It's okay not to know everything.";
	affirmations.at(1) = "I am open and ready to learn.";
	affirmations.at(2) = "I am committed to my personal growth.";
	affirmations.at(3) = "My potential to succeed is limitless";
	affirmations.at(4) = "I am constantly growing and evolving into a better person.";


	srand(time(0));
	int index = rand() % affirmations.size();

	cout << affirmations.at(index);


}