#include <iostream>
using namespace std;
class student {
    public:
        int roll_no,standerd;
        char name[20],division;
        float marks;
        void accept();
        void display();
};
int main() {
cout<<"Enter the Following Details"<<endl;
student s1,s2,s3;
    s1.accept();
    s2.accept();
    s3.accept();
    cout<<"\nDetails of Student"<<endl;
    s1.display();
    s2.display();
    s3.display();
    return 0;
}

void student::accept(){
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
    cout << endl << endl;
}
void student::display(){
    cout<<"\nRoll Number:"<<roll_no<<endl;
    cout<<"Name :" << name << endl;
    cout<<"Standerd :"<<standerd<<endl;
    cout<<"Division :"<<division<<endl;
    cout<< "Marks :" << marks << endl;
}