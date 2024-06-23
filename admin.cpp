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
    shift = 1;
    if (utilsAdmin.listSections(1) == 0) return 0;

    return 1;
}

int Admin::manageStudentInformation()
{
    cout << "Manage Teacher" << endl;
    shift = 2;
    if (utilsAdmin.listSections(2) == 0) return 0;
    
    utilsAdmin.returnButton(choice);
    if (choice == 0) return 0;
    
    return 1;
}