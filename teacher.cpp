#include "teacher.h"
#include "utils.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

Utils& utilsTeacher = Utils::getInstance();

bool Teacher::teacherMenu(string name)
{
    this->name = name;
    utilsTeacher.delayAnimation(200);

    while (true)
    {
        cout << "Welcome, " << name << "!" << endl;
        cout << "[1] View Students" << endl;
        cout << "[2] Logout" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        utilsTeacher.delayAnimation(200);
        switch (choice)
        {
            case 1: if (viewStudents() == 0) continue;
                break;
            case 2: utilsTeacher.logout();
                return true;
            default:
                cout << "Invalid choice, try again" << endl;
                utilsTeacher.delayAnimation(250); 
                continue;
        }
    }

    return false;
}

int Teacher::viewStudents()
{
    cout << "View Students" << endl;
    if (teacherCourses() == 0) return 0;

    return 1;
}

int Teacher::teacherCourses()
{
    while (true){
        ifstream students("teachers.csv");

        cout << left;
        cout << setw(10) << "Number";
        cout << setw(10) << "Course";
        cout << setw(10) << "Section" << "\n";

        vector<string> row;
        string line, word;

        int countItems = 0;
        vector<string> courses;
        vector<string> sections;
        bool checkname, printSection = false;

        while (getline(students, line))
        {
            row.clear();
            std::stringstream s(line);

            while (getline(s, word, ','))
                row.push_back(word); 

            if (row.empty()) continue;

            if (row[0] == "#" && printSection) break;

            if (row[0] == "#"){
                checkname = true;
                continue;
            }

            if (row[0] == name && checkname){
                printSection = true;
                continue;
            }

            if (printSection){
                countItems++;

                cout << setw(10) << countItems;
                cout << setw(10) << row[0];
                cout << setw(10) << row[1] << "\n";

                courses.push_back(row[0]);
                sections.push_back(row[1]);
                continue;
            }
        }

        students.close();

        int userChoice = utilsTeacher.returnButton(choice);
        if (userChoice == 0){
            return 0; break;
        } else {
            if (userChoice > 0 && userChoice <= sections.size() && userChoice <= courses.size()){
                int index = userChoice - 1;
                utilsTeacher.studentsPerSection(sections.at(index), courses.at(index), name);
            }
            else {
                cout << "Invalid number. Try again" << "\n";
                continue;
            }
        }
    }

    return 0;
}

