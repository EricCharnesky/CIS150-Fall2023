#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string getShowName() {
    cout << "Enter the show name" << endl;
    string showName;
    getline(cin, showName);
    showName += ".txt";
    return showName;
}

int main()
{
    int choice = 0;
    string garbage;

    srand(time(0));

    while (choice != 4) {
        cout << "1 - Setup a show to sell tickets for" << endl;
        cout << "2 - Sell tickets for a show" << endl;
        cout << "3 - Print report of tickets for a show" << endl;
        cout << "4 - QUIT" << endl;

        cin >> choice;
        getline(cin, garbage);


        if (choice == 1) {
            string showName = getShowName();
            int numberOfTickets;
            cout << "How many tickets are you going to sell?" << endl;
            cin >> numberOfTickets;

            ofstream outputFile;

            outputFile.open(showName);

            if (!outputFile.is_open()) {
                cout << "Unable to open file!" << endl;
            }
            else{
                for (int ticketNumber = 0; ticketNumber < numberOfTickets; ticketNumber++) {
                    outputFile << ticketNumber << endl;
                    outputFile << endl;
                    outputFile << 0 << endl;
                }

                outputFile.close();
            }
        }
        else if (choice == 2) {
            string showName = getShowName();
            vector<int> ticketNumbers;
            vector<string> customerNames;
            vector<int> confirmationCodes;

            ifstream inputFileStream;
            inputFileStream.open(showName);

            if (!inputFileStream.is_open()) {
                cout << "We don't sell tickets for that show" << endl;
            }
            else {
                while (!inputFileStream.eof()) {
                    int ticketNumber;
                    string customerName;
                    int confirmationCode;

                    inputFileStream >> ticketNumber;
                    getline(inputFileStream, garbage);
                    getline(inputFileStream, customerName);
                    inputFileStream >> confirmationCode;
                    getline(inputFileStream, garbage);

                    ticketNumbers.push_back(ticketNumber);
                    customerNames.push_back(customerName);
                    confirmationCodes.push_back(confirmationCode);
                }

                ticketNumbers.pop_back();
                customerNames.pop_back();
                confirmationCodes.pop_back();

                inputFileStream.close();

                cout << "We have " << ticketNumbers.size() << " tickets to sell" << endl;
                int ticketNumber;
                cout << "What ticket do you want to buy?" << endl;
                cin >> ticketNumber;
                getline(cin, garbage);

                while (ticketNumber >= ticketNumbers.size() || confirmationCodes.at(ticketNumber) != 0) {
                    if (ticketNumber >= ticketNumbers.size()) {
                        cout << "That ticket number is invalid" << endl;
                    }
                    else {
                        cout << "That ticket has already been sold" << endl;
                    }
                    
                    cout << "What ticket do you want to buy?" << endl;
                    cin >> ticketNumber;
                    getline(cin, garbage);
                }

                cout << "Enter your name for the ticket" << endl;
                string customerName;
                getline(cin, customerName);
                customerNames.at(ticketNumber) = customerName;

                confirmationCodes.at(ticketNumber) = rand() % 900000 + 100000;
                
                ofstream outputFile;

                outputFile.open(showName);

                if (!outputFile.is_open()) {
                    cout << "Unable to save ticket sale, please try again!" << endl;
                }
                else {
                    for (int index = 0; index < ticketNumbers.size(); index++) {
                        outputFile << ticketNumbers.at(index) << endl;
                        outputFile << customerNames.at(index) << endl;
                        outputFile << confirmationCodes.at(index) << endl;
                    }

                    outputFile.close();
                }

               
            }
        }
        else if (choice == 3) {
            string showName = getShowName();
            ifstream inputFileStream;
            inputFileStream.open(showName);

            if (!inputFileStream.is_open()) {
                cout << "We don't sell tickets for that show" << endl;
            }
            else {
                while (!inputFileStream.eof()) {
                    int ticketNumber;
                    string customerName;
                    int confirmationCode;

                    inputFileStream >> ticketNumber;
                    getline(inputFileStream, garbage);
                    getline(inputFileStream, customerName);
                    inputFileStream >> confirmationCode;
                    getline(inputFileStream, garbage);

                    cout << "Ticket #" << ticketNumber
                        << " Customer Name: " << customerName
                        << " Confirmation Code: " << confirmationCode << endl;
                }

                inputFileStream.close();
            }
        }
    }
}
