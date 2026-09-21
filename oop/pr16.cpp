#include <iostream>
using namespace std;

class Rectangle {
    float length, breadth;

public:
    void setDimensions(float length, float breadth) {
        this->length = length;
        this->breadth = breadth;
    }

    float area() {
        return this->length * this->breadth;
    }
    
    void display() {
        cout << "Length: " << this->length << endl;
        cout << "Breadth: " << this->breadth << endl;
        cout << "Area: " << this->area() << endl;
    }
};

int main() {
    Rectangle rectangle;
    Rectangle *objectPointer = &rectangle;
    float length, breadth;

    cout << "Enter length: ";
    cin >> length;
    cout << "Enter breadth: ";
    cin >> breadth;

    objectPointer->setDimensions(length, breadth);

    cout << "\nRectangle Details" << endl;
    objectPointer->display();

    return 0;
}