#include "student.h"
#include "utils.h"
#include "admin.h"
#include <iostream>
using std::cout, std::cin, std::endl;

Utils& utilsAdmin = Utils::getInstance();

bool Admin::adminMenu()
{
    utilsAdmin.delayAnimation();

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

        utilsAdmin.delayAnimation();
        switch (choice)
        {
            case 1: if (manageStudent() == 0) 
                continue;
            case 2: if (manageTeacher() == 0) 
                continue;
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
    cout << "Manage Student" << endl;

    utilsAdmin.returnButton(choice);
    if (choice == 0) return 0;

    return 1;
}

int Admin::manageTeacher()
{
    cout << "Manage Teacher" << endl;

    utilsAdmin.returnButton(choice);
    if (choice == 0) return 0;
    
    return 1;
}


