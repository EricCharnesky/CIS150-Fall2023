

#include <iostream>

using namespace std;

class Student {
public:
    // constructors don't have a return type
    // the constructors job is to give values to the class attributes

    // default or no argument
    Student() {
        score = 0;
        name = "";
    }

    Student(string name, double score) {
        this->name = name;
        setScore(score);
        id = rand() % 900000 + 100000;
    }

    void setScore(int score) {
        if (score >= 0 and score <= 100) {
            this->score = score;
        }
        else {
            this->score = 0;
        }
    }

    double getScore() {
        return score;
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    int getID() {
        return id;
    }

private:
    double score;
    string name;
    int id;
};

void printDetailsPointer(Student* student) {
    cout << "Name: " << student->getName() << endl;
    cout << "Score: " << student->getScore() << endl;
    cout << "ID: " << (*student).getID() << endl;
}

void printDetails(Student& student) {
    student.setScore(75);
    cout << "Name: " << student.getName() << endl;
    cout << "Score: " << student.getScore() << endl;
}

int main()
{
    cout << "Hello World!" << endl;

    Student eric;
    eric.setName("Eric");
    eric.setScore(100);

    printDetails(eric);

    cout << "Name: " << eric.getName() << endl;
    cout << "Score: " << eric.getScore() << endl;


    Student* jeb = new Student();
    // pointers use -> instead of . for functions
    jeb->setName("Jeb");
    jeb->setScore(95);
    Student* vivi = new Student("Vivi", 75);

    printDetailsPointer(&eric);
    printDetailsPointer(jeb);
    printDetailsPointer(vivi);


    int number;
    // pointers store memory addresses where their value is stored
    int* numberPointer = nullptr;

    // can't access where a pointer pointed to null is pointing
    //cout << "NumberPointer is: " << numberPointer << endl;

    // crash!
    //// the * next to the variable name says get the value
    //cout << "NumberPointer is pointing at : " << *numberPointer << endl;


    number = 42;
    // set the value of numberPointer to the address of number
    numberPointer = &number;

    cout << "Number is: " << number << endl;

    cout << "NumberPointer is: " << numberPointer << endl;

    // the * next to the variable name says get the value
    cout << "NumberPointer is pointing at : " << *numberPointer << endl;

    number = 777;

    // the * next to the variable name says get the value
    cout << "NumberPointer is pointing at : " << *numberPointer << endl;

    
    for (int array = 0; array < 10000000; array++) {
        int* heapArray = new int[50000];
        cout << array << endl;
        for (int index = 0; index < 50; index++) {
            heapArray[index] = index * 2;
        }
        // frees up the memory in the heap
        //delete[] heapArray;
    }
    
    for (int array = 0; array < 100000; array++) {
        int stackArray[50];
        for (int index = 0; index < 50; index++) {
            stackArray[index] = index * 2;
        }
    }

    int value;
    cin >> value;

}
