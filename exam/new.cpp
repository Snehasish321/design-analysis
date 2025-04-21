#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<iomanip>
#include<sstream>

using namespace std;

class Student {
    public:
    string roll;
    string name;
    string branch;
    float marks;

    Student() {}
    Student (string r , string n , string b , float m) {
        roll = r ;
        name = n ;
        branch = b ;
        marks = m ;
    }
    void input () {
        cout << "Enter Roll No: ";
        cin.ignore();
        getline(cin, roll);
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Branch: ";
        getline(cin,branch);
        cout<< "Enter Marks:" ;
        cin >> marks;
    }

    void display() const {
        cout << setw(13) << roll << " | " << setw(15) << name << " | " << setw(15) << 
        branch << " | " < setw(5) << marks << endl; 
    }
};

class RecordManager {
    private:
    unordered_map<string , Student> students;

    public:
    void addStudent() {
        Student s ;
        s.input();
        if (students.find(s.roll) != students.end()) {
            cout << "Student with this roll no. already exists !!!" << endl;
        } else {
            students[s.roll] = s ;
            cout << "Student added successfully !!!" << endl;
        }
    }

}

int main () {
    return 0 ;
}