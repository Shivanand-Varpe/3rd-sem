#include <iostream>
using namespace std;
class Test {
public:
    int marks;
};
class Sports {
public:
    int score;
};
class Student : public Test, public Sports {
public:
    void display() {
        cout << "Test Marks: " << marks << endl;
        cout << "Sports Score: " << score << endl;
        cout << "Total: " << marks + score << endl;
    }
};
int main() {
    Student student;
    cout << "Enter test marks: ";
    cin >> student.marks;
    cout << "Enter sports score: ";
    cin >> student.score;
    student.display();
    return 0;
}
