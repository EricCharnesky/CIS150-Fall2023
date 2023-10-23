#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// https://learn.zybooks.com/zybook/UMDEARBORNCIS150CharneskyFall2023/chapter/6/section/4
string ProduceSavingsTable(double startAmount, double apr, int numYears, int monthlySavings) {
    // Column widths
    const int YEAR_COL_WIDTH = 5;
    const int BALANCE_COL_WIDTH = 10;

    ostringstream outSS;
    double interest;
    double balance = startAmount;
    int month;
    int totalMonths = numYears * 12;

    // Convert APR to monthly percentage rate and decimal number
    double mpr = apr / 12 * 0.01;

    ofstream outputFile;

    outputFile.open("retirement.txt");

    if (!outputFile.is_open()) {
        return "ERROR";
    }

    // Display 2 decimal places
    outputFile << fixed << setprecision(2);

    // Table heading
    outputFile << setw(YEAR_COL_WIDTH) << "Year"
        << setw(BALANCE_COL_WIDTH) << "Balance" << endl;

    // Calculate interest and ending balance for each month
    for (month = 1; month <= totalMonths; ++month) {
        interest = balance * mpr;
        balance += interest + monthlySavings;

        // Only output year number and balance at the end of the year
        if (month % 12 == 0) {
            outputFile << setw(YEAR_COL_WIDTH) << month / 12
                << setw(BALANCE_COL_WIDTH) << balance << endl;
        }
    }

    outputFile.close();

    // Return the table as a string
    return "please see retirement.txt";
}

int main()
{
    ifstream inputFileStream;

    // windows paths get \\ to escape the \ character
    // absolute path
    // inputFileStream.open("C:\\test\\test.txt");

    // relative path - looks in the folder where the exe is running
    inputFileStream.open("test.txt");

    if (!inputFileStream.is_open()) {
        cout << "Could not open file test.txt." << endl;
        return 1; // non 0 indicates an error
    }


    int number;
    int total = 0;

    // loop until it can't read anymore - reaches EOF - end of file
    while (inputFileStream >> number) {
        total += number;
        cout << number << endl;
    }

    if (!inputFileStream.eof()) {
        cout << "Something bad happened while reading the data" << endl;
    }
    

    inputFileStream.close();

    cout << "Total read: " << total << endl;


    string table;
    double startAmount;
    double apr;
    int years;
    int monthlySavings;

    // Get input values
    cout << "Starting amount?" << endl;
    cin >> startAmount;
    cout << "Annual Percentage Rate?" << endl;
    cin >> apr;
    cout << "Number of years?" << endl;
    cin >> years;

    cout << "How much will you save each month?" << endl;
    cin >> monthlySavings;
    
    cout << endl << "Savings over time:" << endl;
    table = ProduceSavingsTable(startAmount, apr, years, monthlySavings);
    cout << table << endl;

    // output stream
    cout << "Happy Monday!" << endl;

    // input stream
    cin >> number;
    string throwAway;
    // gets the enter key that was pressed
    getline(cin, throwAway);

    cout << "Enter your full name" << endl;
    string name;
    // gets the whole line from the standard input, up until the enter key
    getline(cin, name);

    cout << name;


    string vehicleInfo = "2011 Ford Fiesta";
    istringstream vehicleInfStringStream(vehicleInfo);

    string year;
    string make;
    string model;

    vehicleInfStringStream >> year;
    vehicleInfStringStream >> make;
    vehicleInfStringStream >> model;

    cout << "Your vehicle is a:" << year << " " << make << " " << model << endl;



    return 0;
}
