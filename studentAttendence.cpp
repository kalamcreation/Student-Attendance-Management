#include <bits/stdc++.h>
using namespace std;

// Define a Student class to represent individual students
class Student {
private:
    string name;
    int rollNumber;
    bool present;

public:
    // Constructor to initialize student properties
    Student(string _name, int _rollNumber) : name(_name), rollNumber(_rollNumber), present(false) {}

    // Getter functions
    string getName() const {
        return name;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    bool isPresent() const {
        return present;
    }

    // Mark the student as present
    void markPresent() {
        present = true;
    }

    // Mark the student as absent
    void markAbsent() {
        present = false;
    }
};

// Define an AttendanceSystem class to manage student attendance
class AttendanceSystem {
private:
    vector<Student> students;

public:
    // Add a student to the system
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Mark a student as present based on roll number
    void markPresent(int rollNumber) {
        for (auto& student : students) {
            if (student.getRollNumber() == rollNumber) {
                student.markPresent();
                cout << "Marked " << student.getName() << " as present." << endl;
                return;
            }
        }
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }

    // Mark a student as absent based on roll number
    void markAbsent(int rollNumber) {
        for (auto& student : students) {
            if (student.getRollNumber() == rollNumber) {
                student.markAbsent();
                cout << "Marked " << student.getName() << " as absent." << endl;
                return;
            }
        }
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }

    // Display the attendance record
    void displayAttendance() {
        cout << "Attendance Record:" << endl;
        for (const auto& student : students) {
            cout << "Roll Number: " << student.getRollNumber() << ", Name: " << student.getName()
                 << ", Status: " << (student.isPresent() ? "Present" : "Absent") << endl;
        }
    }
};

int main() {
    AttendanceSystem attendanceSystem;

    while (true) {
        cout << "\nStudent Attendance System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Mark Present" << endl;
        cout << "3. Mark Absent" << endl;
        cout << "4. Display Attendance" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int rollNumber;
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter roll number: ";
                cin >> rollNumber;
                attendanceSystem.addStudent(Student(name, rollNumber));
                cout << "Student added." << endl;
                break;
            }
            case 2: {
                int rollNumber;
                cout << "Enter roll number to mark present: ";
                cin >> rollNumber;
                attendanceSystem.markPresent(rollNumber);
                break;
            }
            case 3: {
                int rollNumber;
                cout << "Enter roll number to mark absent: ";
                cin >> rollNumber;
                attendanceSystem.markAbsent(rollNumber);
                break;
            }
            case 4:
                attendanceSystem.displayAttendance();
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
