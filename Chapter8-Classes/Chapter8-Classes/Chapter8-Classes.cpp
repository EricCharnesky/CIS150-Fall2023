
#include <iostream>
#include <vector>
#include "Ticket.h"

using namespace std;

int main()
{
    string name;
    
    Ticket ericsTicket;
    Ticket jebsTicket(1, "Jeb", 654321);

    //ericsTicket.getConfirmationCode() = 123456;
    //ericsTicket.setConfirmationCode(123456);
    ericsTicket.assignRandomConfirmationCode();
    //ericsTicket.customerName = "Eric Charnesky";
    ericsTicket.setCustomerName("Eric Charnesky");
    //ericsTicket.ticketNumber = 0;
    ericsTicket.setTicketNumber(0);

    vector<Ticket> tickets;
    tickets.push_back(ericsTicket);
    tickets.push_back(Ticket());
    tickets.at(1).assignRandomConfirmationCode();

    for (Ticket ticket : tickets) {
        cout << ticket.getConfirmationCode() << endl;
    }
}
