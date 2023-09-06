#include <iostream>
#include <cmath>
#include <string>

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

	cout << "Enter a number to get the square root of: " << endl;
	double someNumberToGetRootOf;
	cin >> someNumberToGetRootOf;

	cout << "The sqaure root of " << someNumberToGetRootOf
		<< " is " << sqrt(someNumberToGetRootOf) << endl;

	double result = firstNumber * secondNumber;

	int someOtherResult = someNumberToGetRootOf * firstNumber;

	cout << firstNumber << " * " << someNumberToGetRootOf
		<< " = " << someOtherResult << endl;

	// optional digit seperator
	int largestInt = 2'147'483'647;

	cout << "The largest int in C++ is " << largestInt << endl;

	int largestIntPlusSome = largestInt + firstNumber;

	cout << "The largest int + something in C++ is " << largestIntPlusSome << endl;


	string firstName;
	string lastName;

	cout << "Enter your first name: " << endl;
	// cin with a string only goes to white space
	cin >> firstName;
	cout << "Enter your last name: " << endl;
	cin >> lastName;

	cout << "Hi there " << firstName << endl;
	cout << "How are you today? " << endl;


	string trash;
	// use getline to read the entire input including white space
	getline(cin, trash);

	cout << "Oh that's nice!" << endl;

	double pi = 3.1415;
	const double PI_TO_5_DECIMAL_PLACES = 3.14159;


	pi = 5.4;

	// can't change const values
	//PI_TO_5_DECIMAL_PLACES = 10.5;

	double diameter;
	cout << "Enter the diamter of your circle: " << endl;
	cin >> diameter;

	cout << "The circumference is : " << diameter * PI_TO_5_DECIMAL_PLACES << endl;
	
	int number1To10 = rand() % 10 + 1;
	int minValue;
	int maxValue;

	cout << "Enter the minimum random value: " << endl;
	cin >> minValue;
	
	cout << "Enter the maximum random value: " << endl;
	cin >> maxValue;
	
	int randomNumber = rand() % (maxValue - minValue + 1) + minValue;

	cout << "Your lucky number is: " << randomNumber;
}