#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    string branch;
    float marks;

    Student() {}

    Student(int r, string n, string b, float m) {
        rollNo = r;
        name = n;
        branch = b;
        marks = m;
    }

    void input() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Branch: ";
        getline(cin, branch);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() const {
        cout << setw(6) << rollNo << " | " << setw(15) << name << " | "
             << setw(10) << branch << " | " << setw(5) << marks << endl;
    }
};

class RecordManager {
private:
    unordered_map<int, Student> students;

public:
    void addStudent() {
        Student s;
        s.input();
        if (students.find(s.rollNo) != students.end()) {
            cout << "Student with this roll number already exists!" << endl;
            return;
        }
        students[s.rollNo] = s;
        cout << "Student added successfully!\n";
    }

    void deleteStudent(int roll) {
        if (students.erase(roll)) {
            cout << "Student deleted successfully!\n";
        } else {
            cout << "Student not found!\n";
        }
    }

    void searchStudent(int roll) {
        if (students.find(roll) != students.end()) {
            cout << "Student Found:\n";
            cout << "Roll | Name            | Branch     | Marks\n";
            cout << "-----------------------------------------------\n";
            students[roll].display();
        } else {
            cout << "Student not found!\n";
        }
    }

    void showTop3() {
        if (students.empty()) {
            cout << "No students to show!\n";
            return;
        }

        priority_queue<pair<float, int>> pq;
        for (auto &entry : students) {
            pq.push({entry.second.marks, entry.first});
        }

        cout << "\nTop 3 Students:\n";
        cout << "Roll | Name            | Branch     | Marks\n";
        cout << "-----------------------------------------------\n";

        int count = 0;
        while (!pq.empty() && count < 3) {
            int roll = pq.top().second;
            pq.pop();
            students[roll].display();
            count++;
        }
    }

    void displayAll() {
        if (students.empty()) {
            cout << "No students in record.\n";
            return;
        }

        cout << "Roll | Name            | Branch     | Marks\n";
        cout << "-----------------------------------------------\n";
        for (auto &entry : students) {
            entry.second.display();
        }
    }
};

int main() {
    RecordManager manager;
    int choice;

    while (true) {
        cout << "\n===== University Student Record System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Show Top 3 Students\n";
        cout << "5. Show All Students\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.addStudent();
            break;
        case 2: {
            int roll;
            cout << "Enter Roll No to delete: ";
            cin >> roll;
            manager.deleteStudent(roll);
            break;
        }
        case 3: {
            int roll;
            cout << "Enter Roll No to search: ";
            cin >> roll;
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
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
