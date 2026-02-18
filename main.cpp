#include <iostream>
#include<fstream>
using namespace std;
int main(){
}
// ---------- Create Session ----------
void createSession() {
    cout << "Lecture session created successfully!\n\n";
}
void searchStudent() {
    ifstream file("students.txt");
    string line, searchIndex;
    bool found = false;

    cout << "Enter index number to search: ";
    cin.ignore();
    getline(cin, searchIndex);

    while (getline(file, line)) {
        if (line.find(searchIndex) != string::npos) {
            cout << "Student Found: " << line << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }

    file.close();
    cout << endl;
}
