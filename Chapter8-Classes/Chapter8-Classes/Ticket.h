#pragma once

#include <string>

using namespace std;

class Ticket {
private:
    int ticketNumber;
    string customerName;
    int confirmationCode;
public:
    // constructors are special, there is no return type
    // constructors job is to give values to all attributes
    // the goal is no garbage values
    Ticket() {
        ticketNumber = 0;
        customerName = "";
        confirmationCode = 0;
    }

    //Ticket(int ticketNumber) {
    //    setTicketNumber(ticketNumber);
    //    customerName = "";
    //    confirmationCode = 0;
    //}

    Ticket(int ticketNumber, string customerName, int confirmationCode) {
        setTicketNumber(ticketNumber);
        setCustomerName(customerName);
        this->confirmationCode = confirmationCode;
    }

    int getTicketNumber() {
        return ticketNumber;
    }

    string getCusomterName() {
        return customerName;
    }

    int getConfirmationCode() {
        return confirmationCode;
    }

    void setTicketNumber(int ticketNumber) {
        if (ticketNumber < 0) {
            this->ticketNumber = 0;
        }
        else {
            this->ticketNumber = ticketNumber;
        }
    }

    void setCustomerName(string customerName) {
        this->customerName = customerName;
    }

    void assignRandomConfirmationCode() {
        confirmationCode = rand() % 900000 + 100000;
    }
};
