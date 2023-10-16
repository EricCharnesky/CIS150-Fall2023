#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream inputFileStream;
    inputFileStream.open("test.txt");

    double max = DBL_MIN;
    double min = DBL_MAX;
    int count = 0;
    double total = 0;

    if (!inputFileStream.is_open()) {
        cout << "Failed to open file!" << endl;
        return 1;
    }

    double value;

    while (inputFileStream >> value) {

        if (value > max) {
            max = value;
        }
        if (value < min) {
            min = value;
        }
        total += value;
        count++;
    }

    inputFileStream.close();

    double average = total / count;

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Average: " << average << endl;

    inputFileStream.open("test.txt");

    double varianceTotal = 0;

    while (inputFileStream >> value) {
        varianceTotal += pow(value - average, 2);
    }

    inputFileStream.close();

    double standardDeviation = sqrt(varianceTotal / count);

    cout << "Standard deviation: " << standardDeviation << endl;
    
    return 0;
}
