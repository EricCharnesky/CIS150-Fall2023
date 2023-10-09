#ifndef STRINGFUNCTIONS_HPP
#define STRINGFUNCTIONS_HPP


#include <string>
#include <iostream>

using namespace std;

static void upperCaseString(string& someString)
{
	for (int index = 0; index < someString.size(); index++) {
		someString.at(index) = toupper(someString.at(index));
	}
	cout << "Upper cased: " << someString << endl;
}

#endif