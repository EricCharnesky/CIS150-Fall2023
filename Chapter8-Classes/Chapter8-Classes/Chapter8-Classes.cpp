
#include <iostream>

using namespace std;

class Ticket {
private:
    int ticketNumber;
    string customerName;
    int confirmationCode;
public:
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
        this->ticketNumber = ticketNumber;
    }

    void setCustomerName(string customerName) {
        this->customerName = customerName;
    }

    void setConfirmationCode(int confirmationCode) {
        this->confirmationCode = confirmationCode;
    }
};

int main()
{
    string name;
    
    Ticket ericsTicket;
    Ticket jebsTicket;

    //ericsTicket.getConfirmationCode() = 123456;
    ericsTicket.setConfirmationCode(123456);
    //ericsTicket.customerName = "Eric Charnesky";
    ericsTicket.setCustomerName("Eric Charnesky");
    //ericsTicket.ticketNumber = 0;
    ericsTicket.setTicketNumber(0);


}
