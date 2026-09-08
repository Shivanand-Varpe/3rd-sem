#include <iostream>
using namespace std;

// Base class
class Student {
protected:
    int roll_no;
public:
    void get_number(int a) {
        roll_no = a;
    }
    void put_number() {
        cout << "Roll No: " << roll_no << endl;
    }
};

// Intermediate class 1: Test (virtually inherits Student)
class Test : virtual public Student {
protected:
    float part1, part2;
public:
    void get_marks(float x, float y) {
        part1 = x;
        part2 = y;
    }
    void put_marks() {
        cout << "Marks Obtained: " << endl;
        cout << "Part 1 = " << part1 << endl;
        cout << "Part 2 = " << part2 << endl;
    }
};

// Intermediate class 2: Sports (virtually inherits Student)
class Sports : virtual public Student {
protected:
    float score;
public:
    void get_score(float s) {
        score = s;
    }
    void put_score() {
        cout << "Sports Score = " << score << endl;
    }
};

// Derived class: Result inherits from both Test and Sports
class Result : public Test, public Sports {
    float total;
public:
    void display() {
        total = part1 + part2 + score;
        put_number();
        put_marks();
        put_score();
        cout << "Total Score = " << total << endl;
    }
};

int main() {
    Result student;
    int roll;
    float m1, m2, s;

    cout << "Enter Roll Number: ";
    cin >> roll;
    cout << "Enter Marks for Part 1 and Part 2: ";
    cin >> m1 >> m2;
    cout << "Enter Sports Score: ";
    cin >> s;

    student.get_number(roll);
    student.get_marks(m1, m2);
    student.get_score(s);

    cout << "\n----- Student Result -----\n";
    student.display();

    return 0;
}

