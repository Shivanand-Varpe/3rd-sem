#include <iostream>
using namespace std;

inline int add(int a, int b) {
    return a + b;}
inline int sub(int a, int b) {
    return a - b;}
inline int multi(int a, int b) {
    return a * b;}
inline float divide(int a, int b) {
    return a / b;}
int main() {
    int a, b, choice;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Choose operation:\n";
    cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Sum = " << add(a, b) << endl;
            break;
        case 2:
            cout << "Difference = " << sub(a, b) << endl;
            break;
        case 3:
            cout << "Product = " << multi(a, b) << endl;
            break;
        case 4:
            cout << "Quotient = " << divide(a, b) << endl;
            break;
        default:
            cout << "Invalid choice" << endl;}
    return 0;}
