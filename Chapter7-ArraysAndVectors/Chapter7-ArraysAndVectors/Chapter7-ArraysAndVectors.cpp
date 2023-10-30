
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    vector<int> numbers;

    //numbers.push_back(1);
    //numbers.push_back(2);
    //numbers.push_back(3);
    //numbers.push_back(4);
    //numbers.push_back(5);
    
    //cout << numbers.at(0) << endl; // first value

    for (int index = 0; index < numbers.size(); index++) {
        cout << numbers.at(index) << endl;
    }

    cout << "Enter a test score or -1 to stop" << endl;
    int score;
    cin >> score;

    while (score != -1) {
        numbers.push_back(score);
        cout << "Enter a test score or -1 to stop" << endl;
        cin >> score;
    }

    double total = 0;

    // range based for loop - enhanced for loop
    // loops for each value in the vector, assigning it to the varaible on the left
    for (int value : numbers) {
        total += value;
    }

    double average = total / numbers.size();

    int maxScore = INT_MIN;

    // read only
    for (int score : numbers) {
        if (score > maxScore) {
            maxScore = score;
        }
    }

    cout << "Average score: " << total / numbers.size() << endl;

    // score is a copy of the value from numbers
    for (int score : numbers) {
        score += (100 - maxScore);
    }

    for (int index = 0; index < numbers.size(); index++) {
        numbers.at(index) += (100 - maxScore);
    }

    total = 0;
    for (int value : numbers) {
        total += value;
    }

    cout << "new Average score: " << total / numbers.size() << endl;


    vector<int> quantities;
    vector<string> items;
    vector<double> prices;

    string item = "";
    int quantity = 0;
    double price = 0;

    while (item != "STOP") {
        cout << "Enter the name of an item to buy or STOP" << endl;
        cin >> item;
        cout << "Enter the quantity" << endl;
        cin >> quantity;
        cout << "Enter the price" << endl;
        cin >> price;
        if (item != "STOP") {
            items.push_back(item);
            prices.push_back(price);
            quantities.push_back(quantity);
        }
    }


    
}
