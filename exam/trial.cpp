#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<sstream>
#include<iomanip>
#include<algorithm>

using namespace std;

class Student {
    public:
    string roll;
    string name ;
    string branch;
    float marks ;

    Student() {} 

    Student (string r , string n , string b ,float m) {
        roll = r ;
        name = n ;
        branch = b ;
        marks = m ;
    }
    void input() {
        cout << "Enter Roll No: ";
        cin.ignore();
        getline(cin, roll);
        cout << "Enter Name: ";
        getline(cin,name);
        cout << "Enter Branch: ";
        getline(cin,branch);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() const {
        cout << setw(10) << roll << " | " << setw(15) << name << "| " <<
        setw(10) << branch << " | " << setw(5) << marks << endl;
    }
};

class RecordManager {
    private:
    unordered_map<string , Student> students;

    public:
    void addStudent() {
        Student s;
        s.input();

        if (students.find(s.roll) != students.end()) {
            cout << "Student with this roll no. already exists !!! " << endl;
        }
        else {
            students[s.roll] = s ;
            cout << "Student added successfully !!!" << endl ;
        }
    }
    void deleteStudent(string roll) {
        if (students.erase(roll)) {
            cout << "Student with roll no. " << roll << "deleted successfully !!!" << endl ;
        }
        else {
            cout << " Student with roll no. " << roll << " not found !!!"  << endl ;
        }
    }

    void searchStudent(const string& roll) {
        if (students.find(roll) != students.end()) {
            cout << "Students found !! " << endl ;
            cout << " Roll No    |        Name         |   Branch   | Marks  " << endl;
            cout << "--------------------------------------------------------" << endl;
            students[roll].display();
        } else {
            cout << "Student with roll no. " << roll << " not found !!!" << endl;
        }
    }

    void showTop3 () {
        if (students.empty()) {
            cout << "No students to show !!" << endl;
            return ;
        }
        else {
            priority_queue<pair<float,string>> pq;
            for (auto &entry : students) {
                pq.push({entry.second.marks, entry.first});
            }

            cout << "Top 3 Students: " << endl;
            cout << " Roll No    |        Name         |   Branch   | Marks  " << endl;
            cout << "--------------------------------------------------------" << endl;
            int count = 0;
            while (!pq.empty() && count < 3) {
                string roll = pq.top().second;
                pq.pop();
                students[roll].display();
                count++;
            }
        }
    }

    void displayAll() {
        if (students.empty()) {
            cout << "No students in record.\n";
            return;
        }

        cout << "Roll       | Name            | Branch     | Marks\n";
        cout << "---------------------------------------------------\n";
        for (auto &entry : students) {
            entry.second.display();
        }
    }
};

int main () {
    RecordManager manager;
    int choice;
    while (true) {
        cout << " ----- University Record Management System ----- " << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Show Top 3 Students" << endl;
        cout << "5. Display All Students" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2: {
                string roll;
                cout << "Enter Roll No to delete: ";
                cin.ignore();
                getline(cin, roll);
                manager.deleteStudent(roll);
                break;
            }
            case 3: {
                string roll;
                cout << "Enter Roll No to search: ";
                cin.ignore();
                getline(cin, roll);
                manager.searchStudent(roll);
                break;
            }
            case 4:
                manager.showTop3();
                break;
            case 5:
                manager.displayAll();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0 ;
}