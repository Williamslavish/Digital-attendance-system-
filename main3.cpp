
#include <iostream>
#include <fstream>
using namespace std;

// Function declarations
void registerStudent() {
    cout << "Register Student function called\n";
    // Add your implementation
}

void viewStudents() {
    cout << "View Students function called\n";
    // Add your implementation
}

void createSession() {
    cout << "Create Session function called\n";
    // Add your implementation
}

void searchStudent() {
    cout << "Search Student function called\n";
    // Add your implementation
}

void markAttendance() {
    cout << "Mark Attendance function called\n";
    // Add your implementation
}

void viewAttendanceReport() {
    cout << "View Attendance Report function called\n";
    // Add your implementation
}

int main() {
    int choice;
    
    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Create Lecture Session\n";
        cout << "4. Exit\n";
        cout << "5. Search Student\n";
        cout << "6. Mark Attendance\n";
        cout << "7. View Attendance Report\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            registerStudent();
        }
        else if (choice == 2) {
            viewStudents();
        }
        else if (choice == 3) {
            createSession();
        }
        else if (choice == 4) {
            cout << "Goodbye!\n";
        }
        else if (choice == 5){
            searchStudent();
        }
        else if (choice == 6){
            markAttendance();
        }
        else if (choice == 7){
            viewAttendanceReport();
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
