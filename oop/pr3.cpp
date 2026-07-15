#include <iostream>
using namespace std;
int main(){
    int x = 20;
    float y;
    y = x;
    cout << "Implicit Type Casting" << endl;
    cout << "Integer : " << x << endl;
    cout << "Float   : " << y << endl;
    cout << endl;
    float p = 35.89;
    int q;
    q = (int)p;
    cout << "Explicit Type Casting" << endl;
    cout << "Float   : " << p << endl;
    cout << "Integer : " << q << endl;
    return 0;}