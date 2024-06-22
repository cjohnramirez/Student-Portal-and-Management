#include "student.h"
#include "utils.h"
#include "admin.h"
#include <iostream>
using std::cout, std::cin, std::endl;

Utils& utilsAdmin = Utils::getInstance();

bool Admin::adminMenu(string name)
{
    utilsAdmin.delayAnimation(0.25);

    int choice;
    bool runChoice = true;
    while (runChoice)
    {
        cout << "Welcome, " << name << "!" << endl;
        cout << "[1] Manage Student" << endl;
        cout << "[2] Manage Teacher" << endl;
        cout << "[3] Logout" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        utilsAdmin.delayAnimation(0.25);
        switch (choice)
        {
            case 1: if (manageStudent() == 0) continue;
                break;
            case 2: if (manageTeacher() == 0) continue;
                break;
            case 3: utilsAdmin.logout();
                return true;
            default:
                cout << "Invalid choice, try again" << endl;
        }
    }
    
    return false;
}

int Admin::manageStudent()
{
    cout << "Manage Student\n" << endl;
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
                listCourses(sections.at(index));
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
                listStudents(sectionName, courses.at(index));
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

        vector<string> row;
        string line, word;

        bool startFind, findCourse = false;
        string studentName;

        
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
                studentName = row[0];
                if (sectionName == row[2]){
                    cout << setw(20) << studentName;
                    findCourse = true;
                    continue;
                }
            }

            if (findCourse){
                if (courseName == row[0]){
                    cout << setw(15) << row[3];
                    cout << setw(15) << row[4] << "\n";
                }
            }
        }

        int userChoice = utilsAdmin.returnButton(choice);
        if (userChoice == 0){
            return 0; break;
        } else {
            if (userChoice > 0){
                int index = userChoice - 1;
            }
            else {
                cout << "Invalid number. Try again" << "\n";
                continue;
            }
        }
    }

    return 0;
}

int Admin::manageTeacher()
{
    cout << "Manage Teacher" << endl;

    utilsAdmin.returnButton(choice);
    if (choice == 0) return 0;
    
    return 1;
}


