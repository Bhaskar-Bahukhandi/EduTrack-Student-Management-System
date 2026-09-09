#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Student {
public:
    int id;
    string name;
    string branch;
    float percentage;

    Student(int i, string n, string b, float p) {
        id = i;
        name = n;
        branch = b;
        percentage = p;
    }

    char getGrade() {
        if (percentage >= 90) return 'A';
        if (percentage >= 80) return 'B';
        if (percentage >= 70) return 'C';
        if (percentage >= 60) return 'D';
        return 'F';
    }
};

vector<Student> students;

void addStudent() {
    int id;
    string name, branch;
    float percentage;

    cout << "\nEnter Student ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Branch: ";
    getline(cin, branch);

    cout << "Enter Percentage: ";
    cin >> percentage;

    students.push_back(Student(id, name, branch, percentage));
    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    cout << "\n------------- Student Records -------------\n";
    cout << left << setw(10) << "ID"
         << setw(22) << "Name"
         << setw(12) << "Branch"
         << setw(12) << "Percent"
         << "Grade\n";

    for (Student &s : students) {
        cout << left << setw(10) << s.id
             << setw(22) << s.name
             << setw(12) << s.branch
             << setw(12) << s.percentage
             << s.getGrade() << "\n";
    }
}

void searchStudent() {
    int id;

    cout << "\nEnter Student ID to search: ";
    cin >> id;

    for (Student &s : students) {
        if (s.id == id) {
            cout << "\nStudent Found!\n";
            cout << "ID: " << s.id << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "Branch: " << s.branch << "\n";
            cout << "Percentage: " << s.percentage << "%\n";
            cout << "Grade: " << s.getGrade() << "\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void performanceAnalysis() {
    if (students.empty()) {
        cout << "\nNo records available.\n";
        return;
    }

    float total = 0;
    float highest = students[0].percentage;
    string topper = students[0].name;

    for (Student &s : students) {
        total += s.percentage;

        if (s.percentage > highest) {
            highest = s.percentage;
            topper = s.name;
        }
    }

    cout << "\n========== Performance Analysis ==========\n";
    cout << "Number of Students: " << students.size() << "\n";
    cout << fixed << setprecision(2);
    cout << "Class Average: " << total / students.size() << "%\n";
    cout << "Highest Percentage: " << highest << "%\n";
    cout << "Top Performer: " << topper << "\n";
}

int main() {
    students.push_back(Student(101, "Aarav", "CSE", 91));
    students.push_back(Student(102, "Riya", "AI-ML", 84));
    students.push_back(Student(103, "Kabir", "CSE", 76));

    int choice;

    do {
        cout << "\n\n========== EduTrack ==========\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Performance Analysis\n";
        cout << "0. Exit\n";
        cout << "===============================\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                performanceAnalysis();
                break;
            case 0:
                cout << "Exiting EduTrack...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
