#include "teacher.h"
#include "utils.h"
#include <string>
#include <iostream>
using std::string, std::cout, std::endl, std::cin;

Utils& utilsTeacher = Utils::getInstance();

bool Teacher::teacherMenu()
{
    utilsTeacher.delayAnimation();

    int choice;
    bool runChoice = true;
    while (runChoice)
    {
        cout << "Welcome, " << name << "!" << endl;
        cout << "[1] View Students" << endl;
        cout << "[2] Logout" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        utilsTeacher.delayAnimation();
        switch (choice)
        {
            case 1: if (viewStudents() == 0) continue;
                break;
            case 2: utilsTeacher.logout();
                return true;
            default:
                cout << "Invalid choice, try again" << endl; continue;
        }
    }

    return false;
}

int Teacher::viewStudents()
{
    cout << "View Students" << endl;

    utilsTeacher.returnButton(choice);
    if (choice == 0) return 0;
    
    return 1;
}