

#include <iostream>
#include <vector>

using namespace std;

class Item {
private:
    string name;
    int quantity;
    double unitPrice;
public:
    double getTotalPrice() {
        return quantity * unitPrice;
    }

    string getName() {
        return name;
    }

    int getQuantity() {
        return quantity;
    }

    double getUnitPrice() {
        return unitPrice;
    }

    void setName(string name) {
        this->name = name;
    }

    void setQuantity(int quantity) {
        if (quantity > 0) {
            this->quantity = quantity;
        }
        else {
            this->quantity = 1;
        }
    }

    void setUnitPrice(double unitPrice) {
        if (unitPrice > 0) {
            this->unitPrice = unitPrice;
        }
        else {
            this->unitPrice = 1;
        }
    }
};

int main()
{
    vector<Item> items;

    for (int itemNumber = 1; itemNumber <= 3; itemNumber++) {
        Item item;
        item.setName("whatever");
        item.setQuantity(itemNumber);
        item.setUnitPrice(1.5);

        items.push_back(item);
    }

    double grandTotal = 0;

    for (Item item : items) {
        cout << item.getQuantity() << " " << item.getName() << " @ $"
            << item.getUnitPrice() << " - " << item.getTotalPrice() << endl;
        grandTotal += item.getTotalPrice();
    }

    //for (int index = 0; index < items.size(); index++) {
    //    cout << items.at(index).getQuantity() << " " << items.at(index).getName() << " @ $"
    //        << items.at(index).getUnitPrice() << " - " << items.at(index).getTotalPrice() << endl;
    //}

    cout << "Total: $" << grandTotal << endl;
}