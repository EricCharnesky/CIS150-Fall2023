#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void writeToFile(string filename, bool append = false) {
    ofstream outputFile;
    
    if (append) {
        outputFile.open(filename, ios_base::app);
    }
    else {
        outputFile.open(filename);
    }

    string item = "";

    while (item != "STOP") {
        cout << "What do you want to add to the list or STOP?" << endl;

        getline(cin, item);

        if (item != "STOP") {
            outputFile << item << endl;
        }
        
    }

    outputFile.close();
}

int main()
{
    string moreLists = "Y";

    while (toupper(moreLists.at(0)) == 'Y') {
        string list;
        cout << "Enter the name of a list" << endl;
        getline(cin, list);

        ifstream inputFileStream;

        inputFileStream.open(list + ".txt");

        if (inputFileStream.is_open()) {
            cout << "Here's what's in your list currently: " << endl;
            string line;
            while (!inputFileStream.eof()) {
                getline(inputFileStream, line);
                cout << line << endl;
            }

            inputFileStream.close();

            cout << "Do you want to add to this list or start fresh? (add/fresh)" << endl;
            string add;
            getline(cin, add);

            if (add == "add") {
                writeToFile(list + ".txt", true);
            }
            else {
                writeToFile(list + ".txt");
            }
        }
        else {
            writeToFile(list + ".txt");
        }


        cout << "Enter more lists? Y/N" << endl;
        getline(cin, moreLists);


    }
}
