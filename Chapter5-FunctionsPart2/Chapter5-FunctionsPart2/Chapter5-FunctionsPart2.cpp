#include <iostream>
#include <cmath>
#include <string>
#include "StringFunctions.hpp"

using namespace std;

const int myFavoriteNumber = 777;

// function prototype
int addTenToNumber(int& number);

// overloaded - same name, different parameters
void printDate(string month, string day, string year = "2023") {
    cout << "American format " << month << "/" << day << "/" << year << endl;
    cout << "European format " << day << "/" << month << "/" << year << endl;
    cout << "ISO format " << year << "-" << month << "-" << day << endl;
}

void printDate(int month, int day, int year = 2023) {
    cout << "American format " << month << "/" << day << "/" << year << endl;
    cout << "European format " << day << "/" << month << "/" << year << endl;
    cout << "ISO format " << year << "-" << month << "-" << day << endl;
}



bool findXInterceptsForQuadratic(double a, double b, double c, 
                                double& xIntercept1, double& xIntercept2)
{
    if (a == 0) {
        cout << "That's not quadratic..." << endl;
    }

    double determinant = (b * b) - (4 * a * c);
    if (determinant <= 0) {
        return false;
    }
    xIntercept1 = (-b + sqrt(determinant)) / (2 * a);
    xIntercept2 = (-b - sqrt(determinant)) / (2 * a);
    return true;
}



int main()
{
    printDate(10, 9);
    printDate(7, 7, 2007);

    printDate("October", "9th");

    string name;
    cout << "Enter your name" << endl;
    cin >> name;

    upperCaseString(name);
    cout << "Name in main: " << name << endl;

    int myFavoriteNumber = 42;
    cout << myFavoriteNumber << endl;

    int myNewFavoriteNumber = addTenToNumber(myFavoriteNumber);

    cout << myFavoriteNumber << endl;
    cout << myNewFavoriteNumber << endl;

    double a;
    double b;
    double c;
    double xIntercept1;
    double xIntercept2;

    cout << "Enter values for a, b, and c for the formula aX^2 + bX + c" << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    if (findXInterceptsForQuadratic(a, b, c, xIntercept1, xIntercept2)) {
        cout << "The intercepts are " << xIntercept1 << ", " << xIntercept2 << endl;
    }
    else {
        cout << "There are no intercepts" << endl;
    }

}

// you can modify the value when you pass by reference
int addTenToNumber(int& number)
{
    number += 10;
    return number;
}