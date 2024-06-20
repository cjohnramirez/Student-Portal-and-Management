#include "student.h"
#include "utils.h"
#include "admin.h"
#include <iostream>
#include <windows.h>
using std::cout, std::cin, std::endl;

Utils utils4;

bool Admin::adminMenu()
{
    utils4.delayAnimation();

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

        if (choice == 1 || choice == 2 || choice == 3)
        {   
            if (choice == 1){
                utils4.delayAnimation();
                if (manageStudent() == 0) 
                continue;
            }
            else if (choice == 2){
                utils4.delayAnimation();
                if (manageTeacher() == 0) continue;
            }
            else if (choice == 3){
                utils4.logout();
                return true;
            }

        } else {
            cout << "Invalid choice, try again" << endl;
        }
    }
    
    return false;
}

int Admin::manageStudent()
{
    cout << "Manage Student" << endl;

    utils4.returnButton(choice);
    if (choice == 0) return 0;

    return 1;
}

int Admin::manageTeacher()
{
    cout << "Manage Teacher" << endl;

    utils4.returnButton(choice);
    if (choice == 0) return 0;
    
    return 1;
}


