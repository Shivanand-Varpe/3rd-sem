#include <iostream>
#include <iomanip>
using namespace std;
int num = 100;
class Demo{
public:
    void display();
};
void Demo::display(){
    int num = 50;
    cout << "Local Number  : " << num << endl;
    cout << "Global Number : " << ::num << endl;}
int main(){
    cout << "Program Started..." << flush;
    int *ptr = new int;
    *ptr = 25;
    cout << endl << endl;
    cout << "Value using new : " << *ptr << endl;
    Demo d;
    d.display();
    cout << setfill('*') << setw(30) << "" << endl;
    cout << setfill(' ');
    float pi = 3.14159;
    cout << fixed << setprecision(2);
    cout << "Pi = " << pi << endl;
    cout << "C++ Programming" << ends << endl;
    int n = 25;
    cout << "Decimal : " << setbase(10) << n << endl;
    cout << "Octal   : " << setbase(8) << n << endl;
    cout << "Hex     : " << setbase(16) << n << endl;
    delete ptr;
    return 0;}