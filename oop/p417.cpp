#include <iostream>
using namespace std;
class singlebase {
protected:
    int bv;
public:
    void setbv(int value) {
        bv = value;}
};
class singlederived : public singlebase {
    int dv;
public:
    void setdv(int value) {
        dv = value;}
    void show() {
        cout << "Base value: " << bv << endl;
        cout << "Derived value: " << dv << endl;
        cout << "Total: " << bv + dv << endl;}
};
class multilevelbase {
protected:
    int v1;
public:
    void setv1(int value) {
        v1 = value;}
};
class derived1 : public multilevelbase {
protected:
    int v2;
public:
    void setv2(int value) {
        v2 = value;}
};
class derived2 : public derived1 {
    int v3;
public:
    void setv3(int value) {
        v3 = value;}
    void show() {
        cout << "First value: " << v1 << endl;
        cout << "Second value: " << v2 << endl;
        cout << "Third value: " << v3 << endl;
        cout << "Total: " << v1 + v2 + v3 << endl;}
};
int main() {
    int a, b, c, d, e;
    cout << "Pointer to derived class in single inheritance" << endl;
    cout << "Enter base and derived values: ";
    cin >> a >> b;
    singlederived so;
    singlederived *sp = &so;
    sp->setbv(a);
    sp->setdv(b);
    cout << "\nSingle Inheritance Details" << endl;
    sp->show();
    cout << "\nPointer to derived class in multilevel inheritance" << endl;
    cout << "Enter three values: ";
    cin >> c >> d >> e;
    derived2 mo;
    derived2 *mp = &mo;
    mp->setv1(c);
    mp->setv2(d);
    mp->setv3(e);
    cout << "\nMultilevel Inheritance Details" << endl;
    mp->show();
    return 0;}