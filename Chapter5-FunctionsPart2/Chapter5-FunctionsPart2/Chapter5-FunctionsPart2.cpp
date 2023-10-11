#include <iostream>
#include <cmath>
#include <string>
#include "StringFunctions.hpp"

using namespace std;

const int myFavoriteNumber = 777;

// function prototype
int addTenToNumber(int& number);

// bad fib - really really slow - adds a bunch of 1s
int fibonacci(int nth) {
    // this might be overkill
    if (nth <= 0) {
        return 0;
    }
    else if (nth <= 2) {
        return 1;
    }
    return fibonacci(nth - 1) + fibonacci(nth - 2);
}

int _fibonacciBetterRecursion(int nth, int currentNth, int previous, int current) {
    if (nth == currentNth) {
        return current;
    }
    return _fibonacciBetterRecursion(nth, currentNth + 1, current, current + previous);
}

int fibonacciBetterRecursion(int nth) {
    if (nth <= 0) {
        return 0;
    }
    else if (nth <= 2) {
        return 1;
    }
    return _fibonacciBetterRecursion(nth, 3, 1, 2);
}



int fibonacciIterative(int nth) {
    // this might be overkill
    if (nth <= 0) {
        return 0;
    }
    else if (nth <= 2) {
        return 1;
    }
    int currentNth = 3;
    int current = 2;
    int previous = 1;

    while (currentNth != nth) {
        int next = current + previous;
        previous = current;
        current = next;
        currentNth++;
    }

    return current;
}

void countDown(int number) {
    cout << number << endl;
    if (number > 0) {
        countDown(number - 1);
    }
    else {
        cout << "Blast off!" << endl;
    }
}

// infinite recursion
void printIsItOverYet()
{
    cout << "Is it over yet?!?" << endl;
    printIsItOverYet();
}

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
    for (int nth = 1; nth < 47; nth++) {
        cout << nth << ": " << fibonacciBetterRecursion(nth) << endl;
    }

    countDown(10);
    //printIsItOverYet();

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