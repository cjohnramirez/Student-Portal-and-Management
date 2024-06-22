#include "student.h"
#include "utils.h"
#include "admin.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

Utils& utilsAdmin = Utils::getInstance();

bool Admin::adminMenu(string name)
{
    utilsAdmin.delayAnimation(200);

    int choice;
    bool runChoice = true;
    while (runChoice)
    {
        cout << "Welcome, " << name << "!" << endl;
        cout << "[1] Manage Student Grades" << endl; //done
        cout << "[2] Manage Student Information" << endl;
        cout << "[3] Add Student" << endl;
        cout << "[4] Delete Student" << endl;
        cout << "[n/a] Add or Delete Teacher" << endl;
        cout << "[5] Logout" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        utilsAdmin.delayAnimation(250);
        switch (choice)
        {
            case 1: if (manageStudentGrades() == 0) continue;
                break;
            case 2: if (manageStudentInformation() == 0) continue;
                break;
            case 3: 
                break;
            case 4: 
                break;
            case 5: utilsAdmin.logout();
                return true;
            default:
                cout << "Invalid choice, try again" << endl;
        }
    }
    
    return false;
}

int Admin::manageStudentGrades()
{
    cout << "Manage Student Grades" << endl;
    this->shift = 1;
    if (listSections() == 0) return 0;

    return 1;
}

int Admin::listSections(){

    cout << "Select section:" << endl;

    while (true){
        ifstream students("sections.csv");

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> sections;

        cout << left;
        cout << setw(10) << "Number";
        cout << setw(10) << "Section" << "\n";

        while (getline(students, line))
        {
            row.clear();
            std::stringstream s(line);

            while (getline(s, word, ','))
                row.push_back(word); 

            if (row.empty()) continue;

            sections.push_back(row[0]);
            countItems++;

            cout << setw(10) << countItems;
            cout << setw(10) << row[0] << "\n";
        }

        students.close();

        int userChoice = utilsAdmin.returnButton(choice);
        if (userChoice == 0){
            return 0; break;
        } else {
            if (userChoice > 0 && userChoice <= sections.size()){
                int index = userChoice - 1;
                if (shift == 1) listCourses(sections.at(index));
                else if (shift == 2) listStudents(sections.at(index));
            }
            else {
                cout << "Invalid number. Try again" << "\n";
                continue;
            }
        }
    }
}

int Admin::listCourses(string sectionName){
    cout << "Select course:" << endl;

    while (true){
        ifstream students("students.csv");

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> courses;

        cout << left;
        cout << setw(10) << "Number";
        cout << setw(10) << "Course" << "\n";
        bool checkSection, printCourses = false;

        while (getline(students, line))
        {
            row.clear();
            std::stringstream s(line);

            while (getline(s, word, ','))
                row.push_back(word); 

            if (row.empty()) continue;

            if (row[0] == "#" && printCourses) break;

            if (row[0] == "#"){
                checkSection = true;
                continue;
            }

            if (row[2] == sectionName && checkSection){
                printCourses = true;
                continue;
            }

            if (printCourses){
                countItems++;

                cout << setw(10) << countItems;
                cout << setw(10) << row[0] << "\n";

                courses.push_back(row[0]);
                continue;
            }
        }

        students.close();

        int userChoice = utilsAdmin.returnButton(choice);
        if (userChoice == 0){
            return 0; break;
        } else {
            if (userChoice > 0 && userChoice <= courses.size()){
                int index = userChoice - 1;

                listStudents(sectionName, courses.at(index)); //edit student grade
                //edit student
                utilsAdmin.delayAnimation(200);
            }
            else {
                cout << "Invalid number. Try again" << "\n";
                continue;
            }
        }
    }

    return 0;
}

int Admin::listStudents(string sectionName, string courseName)
{
    while (true){
        ifstream students("students.csv");

        cout << left;
        cout << setw(15) << "Number";
        cout << setw(20) << "Name";
        cout << setw(15) << "Midterm";
        cout << setw(15) << "Final" << "\n";

        int countItem = 0;
        vector<string> row;
        string line, word;

        bool startFind, findCourse = false;
        string studentName;

        vector<string> names;
        vector<string> midterm;
        vector<string> final;

        while (getline(students, line))
        {
            row.clear();
            std::stringstream s(line);

            while (getline(s, word, ','))
                row.push_back(word);

            if (row[0] == "#"){
                startFind = true;
                continue;
            }

            if (startFind){
                studentName = row[1];
                if (sectionName == row[2]){
                    countItem++;

                    cout << setw(15) << countItem;
                    names.push_back(studentName);
                    cout << setw(20) << studentName;
                    findCourse = true;
                    continue;
                }
            }

            if (findCourse){
                if (courseName == row[0]){
                    midterm.push_back(row[3]);
                    final.push_back(row[4]);

                    cout << setw(15) << row[3];
                    cout << setw(15) << row[4] << "\n";
                }
            }
        }

        while (true) {
            cout << "[0] Back" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (cin.fail()){
                cout << "Not an integer. Try again." << endl;
                cin.clear();
                cin.ignore(256,'\n');
                continue;
            } else 
                break;
        }

        if (choice == 0){
            return 0; break;
        } else {
            if (choice > 0){
                int index = choice - 1;
                string semesterChoice; int semesterNumber;

                cout << "\nEnter semester [m/f]: ";
                cin >> semesterChoice;
                if (semesterChoice == "m") semesterNumber = 3;
                else if (semesterChoice == "f") semesterNumber = 4;
                else {
                    cout << "Invalid value. Try again" << "\n";
                    continue;
                }

                double grade;
                cout << "Enter grade: ";
                cin >> grade;

                if (cin.fail()){
                    cout << "Invalid value. Try again" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    continue;
                }

                utilsAdmin.modifyStudentGrades(names.at(index), courseName, semesterNumber, grade);
            }
            else {
                cout << "Invalid number. Try again" << "\n";
                continue;
            }
        }
    }

    return 0;
}

int Admin::manageStudentInformation()
{
    cout << "Manage Teacher" << endl;
    this->shift = 2;
    if (listSections() == 0) return 0;
    
    utilsAdmin.returnButton(choice);
    if (choice == 0) return 0;
    
    return 1;
}

int Admin::listStudents(string sectionName)
{
    while (true){
        ifstream students("students.csv");

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> studentList;

        cout << left;
        cout << setw(10) << "Number";
        cout << setw(10) << "Student" << "\n";
        bool checkSection, printStudent = false;

        while (getline(students, line))
        {
            row.clear();
            std::stringstream s(line);

            while (getline(s, word, ','))
                row.push_back(word); 

            if (row.empty()) continue;

            if (row[0] == "#"){
                checkSection = true;
                continue;
            }

            if (row[2] == sectionName && checkSection){
                printStudent = true;
            }

            if (printStudent){
                countItems++;

                cout << setw(10) << countItems;
                cout << setw(10) << row[1] << "\n";

                studentList.push_back(row[1]);

                printStudent = false;
                continue;
            }
        }

        students.close();

        int userChoice = utilsAdmin.returnButton(choice);
        if (userChoice == 0){
            return 0; break;
        } else {
            if (userChoice > 0 && userChoice <= studentList.size()){
                int index = userChoice - 1;

                listStudentInformation(studentList.at(index), sectionName); 
                
                utilsAdmin.delayAnimation(200);
            }
            else {
                cout << "Invalid number. Try again" << "\n";
                continue;
            }
        }
    }

    return 1;
}

int Admin::listStudentInformation(string studentName, string sectionName){
    
    while (true){
        ifstream students("students.csv");

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> studentList;

        bool checkSection, printStudent = false;

        cout << left;
        while (getline(students, line))
        {
            row.clear();
            std::stringstream s(line);

            while (getline(s, word, ','))
                row.push_back(word); 

            if (row.empty()) continue;

            if (row[0] == "#"){
                checkSection = true;
                continue;
            }

            if (row[2] == sectionName && checkSection){
                printStudent = true;
            }

            if (studentName == row[1] && printStudent){
                cout << left;
                cout << setw(10) << "Number" << setw(30) << "Label" << setw(15) << "Information" << "\n";
                cout << setw(10) << "1" << setw(30) << "Name" << setw(15) << row[1] << "\n";
                cout << setw(10) << "2" << setw(30) << "Section" << setw(15) << row[2] << "\n"; 
                cout << setw(10) << "3" << setw(30) << "Program" << setw(15) << row[3] << "\n";
                cout << setw(10) << "4" << setw(30) << "Phone Number" << setw(15) << row[4] << "\n"; 
                cout << setw(10) << "5" << setw(30) << "Email" << setw(15) << row[5] << "\n";

                printStudent = false;
                break;
            }
        }

        students.close();

        int userChoice = utilsAdmin.returnButton(choice);
        if (userChoice == 0){
            return 0; break;
        } else {
            if (userChoice > 0 && userChoice <= 5 && userChoice != 2 && userChoice != 3){
                int index = userChoice;

                cin.ignore();
                string toReplace;
                cout << "Enter Replacement: ";
                getline(cin, toReplace);

                utilsAdmin.modifyStudentInformation(studentName, toReplace, index); 
            } else if (userChoice == 2) {
                cout << "Changing section is not allowed here." << endl;
            } else if (userChoice == 3) {
                cout << "Changing program is not allowed here." << endl;
            } else {
                cout << "Invalid number. Try again" << "\n";
                continue;
            }
        }
    }
}
