#include <iostream>
using namespace std; 

int main() {
	cout << "Happy Wednesday!" << endl;	

	cout << "It's nice to have internet again!" << endl;
	
	cout << 7 * 7 << endl;	
	cout << "7 * 7" << endl;

	cout << 7 / 5 << endl;	
	cout << "7 / 5" << endl;

	cout << 7.0 / 5.0 << endl;
	cout << "7.0 / 5.0" << endl;

	double dollarsPerHour;
	cout << "Enter your hourly wage: " << endl;
	cin >> dollarsPerHour;

	cout << "If you make " << dollarsPerHour << " / hour, you would make $"
		<< dollarsPerHour * 40 << " per week ( before taxes )" << endl
		<< "That works out to $"
		<< dollarsPerHour * 40 * 52 << " per year" << endl;

	int firstNumber;
	int secondNumber;

	cout << "Enter your first interger: " << endl;
	cin >> firstNumber;

	cout << "Enter your second interger: " << endl;
	cin >> secondNumber;

	cout << "First number + second number : "
		<< firstNumber + secondNumber << endl;

	cout << "First number - second number : "
		<< firstNumber - secondNumber << endl;

	cout << "First number * second number : "
		<< firstNumber * secondNumber << endl;

	cout << "First number / second number : "
		<< firstNumber / secondNumber  
		<< " remainder: " << firstNumber % secondNumber << endl;


}