#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void printStudentData(string studentName, int project1Score, int project2Score) {
    ofstream outputFile;
    // DANGER WILL ROBINSON
     // opening a file will overwrite it
    // https://stackoverflow.com/questions/2393345/how-to-append-text-to-a-text-file-in-c
    outputFile.open("gradebook.txt", ios_base::app);
    if (!outputFile.is_open()) {
        cout << "UNABLE TO OPEN FILE!";
    }
    else {
        outputFile << studentName << endl;
        outputFile << project1Score << endl;
        outputFile << project2Score << endl;

        outputFile.close();
    }

}

void readStudentData(string fileName) {
    ifstream inputFileStream;
    inputFileStream.open(fileName);

    if (!inputFileStream.is_open()) {
        cout << "Could not open file test.txt." << endl;
    } 
    else {
        string name;
        int project1Score;
        int project2Score;

        while (inputFileStream >> name >> project1Score >> project2Score) {
            cout << name << " - Project 1 score: "
                << project1Score << " - Project 2 score: " << project2Score << endl;
        }

        inputFileStream.close();
    }


}

int main()
{
    printStudentData("Eric", 100, 100);
    printStudentData("Jeb", 90, 90);

    readStudentData("gradebook.txt");
}
