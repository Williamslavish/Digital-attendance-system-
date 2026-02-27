#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <fstream>   // For exporting to Excel (CSV)

using namespace std;

// ------------------ Student Structure ------------------
struct Student {
    string indexNumber;
    string fullName;
    string attendance;
};

// Temporary storage (RAM only)
vector<Student> students;

// ------------------ Check Duplicate Index ------------------
bool indexExists(const string& indexNumber) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].indexNumber == indexNumber) {
            return true;
        }
    }
    return false;
}

// ------------------ Validate Index Number ------------------
bool isValidIndex(const string& indexNumber) {
    if (indexNumber.length() != 9) return false;

    for (int i = 0; i < 8; i++) {
        if (!isdigit(indexNumber[i])) return false;
    }

    if (!isalpha(indexNumber[8])) return false;

    return true;
}

// ------------------ Register Student ------------------
void registerStudent() {
    string indexNumber, fullName, answer;

    while (true) {
        cout << "\nEnter Index Number: ";
        cin >> indexNumber;

        if (!isValidIndex(indexNumber)) {
            cout << "Error: Invalid format! Must be 8 digits followed by a letter.\n";
            continue;
        }

        if (indexExists(indexNumber)) {
            cout << "Error: Index number already exists!\n";
            continue;
        }

        cout << "You entered " << indexNumber << ". Confirm? (Y/N): ";
        cin >> answer;

        for (size_t i = 0; i < answer.size(); i++)
            answer[i] = tolower(answer[i]);

        if (answer == "y" || answer == "yes") {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Full Name: ";
            getline(cin, fullName);

            Student s;
            s.indexNumber = indexNumber;
            s.fullName = fullName;
            s.attendance = "Not Marked";

            students.push_back(s);

            cout << "Student Registered Successfully!\n";
            return;
        }
        else {
            cout << "Try again.\n";
        }
    }
}

// ------------------ View Students ------------------
void viewStudents() {
    cout << "\n--- Students ---\n";

    if (students.empty()) {
        cout << "No students registered yet.\n";
        return;
    }

    for (size_t i = 0; i < students.size(); i++) {
        cout << i + 1
             << ". Index: " << students[i].indexNumber
             << " | Name: " << students[i].fullName
             << " | Attendance: " << students[i].attendance
             << endl;
    }
}

// ------------------ Search Student ------------------
void searchStudent() {
    if (students.empty()) {
        cout << "No students registered yet.\n";
        return;
    }

    string searchIndex;
    cout << "\nEnter index number to search: ";
    cin >> searchIndex;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].indexNumber == searchIndex) {
            cout << "\nStudent Found!\n";
            cout << "Index: " << students[i].indexNumber << endl;
            cout << "Name: " << students[i].fullName << endl;
            cout << "Attendance: " << students[i].attendance << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

// ------------------ Mark Attendance ------------------
void markAttendance() {
    if (students.empty()) {
        cout << "No students registered yet.\n";
        return;
    }

    string indexTaken;
    cout << "Enter index to mark attendance: ";
    cin >> indexTaken;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].indexNumber == indexTaken) {

            char status;
            cout << "Enter Status (P = Present, L = Late, A = Absent): ";
            cin >> status;

            if (status == 'P' || status == 'p')
                students[i].attendance = "Present";
            else if (status == 'L' || status == 'l')
                students[i].attendance = "Late";
            else if (status == 'A' || status == 'a')
                students[i].attendance = "Absent";
            else {
                cout << "Invalid status.\n";
                return;
            }

            cout << "Attendance recorded successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

// ------------------ Update Attendance ------------------
void updateAttendance() {
    if (students.empty()) {
        cout << "No students registered yet.\n";
        return;
    }

    string indexUpdate;
    cout << "Enter index number to update attendance: ";
    cin >> indexUpdate;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].indexNumber == indexUpdate) {

            cout << "Current Status: " << students[i].attendance << endl;

            char newStatus;
            cout << "Enter New Status (P = Present, L = Late, A = Absent): ";
            cin >> newStatus;

            if (newStatus == 'P' || newStatus == 'p')
                students[i].attendance = "Present";
            else if (newStatus == 'L' || newStatus == 'l')
                students[i].attendance = "Late";
            else if (newStatus == 'A' || newStatus == 'a')
                students[i].attendance = "Absent";
            else {
                cout << "Invalid status.\n";
                return;
            }

            cout << "Attendance Updated Successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

// ------------------ Export to Excel (CSV) ------------------
void exportToExcel() {
    if (students.empty()) {
        cout << "No students to export.\n";
        return;
    }

    ofstream file("Attendance_List.csv");

    if (!file) {
        cout << "Error creating file!\n";
        return;
    }

    file << "Index Number,Full Name,Attendance\n";

    for (size_t i = 0; i < students.size(); i++) {
        file << students[i].indexNumber << ","
             << students[i].fullName << ","
             << students[i].attendance << "\n";
    }

    file.close();

    cout << "Attendance exported successfully to Attendance_List.csv\n";
}

// ------------------ Main ------------------
int main() {
    int choice;

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout << "1. Register student\n";
        cout << "2. View students\n";
        cout << "3. Search student\n";
        cout << "4. Mark Attendance\n";
        cout << "5. Update Attendance\n";
        cout << "6. Export Attendance to Excel\n";
        cout << "0. Exit\n";
        cout << "Choice:-> ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number.\n";
            continue;
        }

        switch(choice) {
            case 1: registerStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: markAttendance(); break;
            case 5: updateAttendance(); break;

    } while(choice != 0);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main(){
}


    // Open a file for writing
    FILE *excelFile = fopen("output.csv", "w");
    
    if (excelFile == NULL) {
        printf("Error creating file!");
        return 1;
    }
    
    // Write headers (column names)
    fprintf(excelFile, "Column1,Column2,Column3\n");
    
    // Write your data
    fprintf(excelFile, "data1,data2,data3\n");
    fprintf(excelFile, "more1,more2,more3\n");
    
    // Close the file
            case 6: exportToExcel(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    fclose(excelFile);
    
    printf("Data saved to output.csv - open with Excel!");
    return 0;
}
