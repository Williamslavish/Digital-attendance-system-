#include <iostream>
#include<fstream>
using namespace std;

int main(){
}
void markAttendance(){

    string index, status;

    ofstream file("attendance.txt", ios::app);

    cout << "Enter student index number: ";
    cin.ignore();
    getline(cin, index);

    cout << "Enter attendance (P = Present, A = Absent, L = Late): ";
    getline(cin, status);

    file << index << " - " << status << endl;
    file.close();

    cout << "Attendance recorded successfully!\n\n";
}
void viewAttendanceReport() {
    ifstream file("attendance.txt");
    string line;
    int present = 0, absent = 0, late = 0;

    cout << "\n--- Attendance Report ---\n";

    while (getline(file, line)) {
        cout << line << endl;

        if (line.find("P") != string::npos)
            present++;
        else if (line.find("A") != string::npos)
            absent++;
        else if (line.find("L") != string::npos)
            late++;
    }

    cout << "\nSummary:\n";
    cout << "Present: " << present << endl;
    cout << "Absent: " << absent << endl;
    cout << "Late: " << late << endl << endl;

    file.close();
}







