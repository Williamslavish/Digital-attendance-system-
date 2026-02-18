#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string indexNumber;
    string name;
};

vector<Student> students;

void registerStudent() {
    Student s;
    cout << "Enter Index Number: ";
    cin >> s.indexNumber;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);

    students.push_back(s);
    cout << "Student registered successfully!\n";
}

void viewStudents() {
    cout << "\n--- REGISTERED STUDENTS ---\n";
    for (int i = 0; i < students.size(); i++) {
        cout << i + 1 << ". "
             << students[i].indexNumber << " - "
             << students[i].name << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\nDIGITAL ATTENDANCE SYSTEM\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerStudent();
            break;
        case 2:
            viewStudents();
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
