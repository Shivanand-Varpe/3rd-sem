/*Write programs to show use of classes and
objects to define the function inside the class*/
#include <iostream>
using namespace std;
class student {
public:
    int roll_no,standerd;
    char name[20],division;
    float marks;
    void accept() {
        cout << "\nRoll Number:";
        cin >> roll_no;
        cout << "Name :";
        cin >> name;
        cout << "Standerd :";   
        cin >> standerd;
        cout << "Division :";
        cin >> division;
        cout << "Marks :";
        cin >> marks;
        cout << endl << endl;}
    void display() {
        cout << "\nRoll Number:" << roll_no << endl;
        cout << "Name :" << name << endl;
        cout << "Standerd :" << standerd << endl;
        cout << "Division :" << division << endl;
        cout << "Marks :" << marks << endl;}};
int main() {
    cout << "Enter the Following Details" << endl;
    student s1, s2;
    s1.accept();
    s2.accept();
    cout << "\nDetails of Student 1" << endl;
    s1.display();
    cout << "\nDetails of Student 2" << endl;
    s2.display();
    return 0;}