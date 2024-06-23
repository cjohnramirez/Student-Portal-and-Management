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
    int choice;
    bool runChoice = true;
    while (runChoice)
    {
        cout << "\033[94m" << R"(     _    ____  __  __ ___ _   _ 
    / \  |  _ \|  \/  |_ _| \ | |
   / _ \ | | | | |\/| || ||  \| |
  / ___ \| |_| | |  | || || |\  |
 /_/   \_\____/|_|  |_|___|_| \_|
                                 )" << "\033[0m" << endl;
        cout << "Welcome, " << name << "!\n" << endl;
        cout << "\033[32m[1]\033[0m Manage Student Grades" << endl; //done
        cout << "\033[32m[2]\033[0m Manage Student Information" << endl;
        cout << "\033[32m[3]\033[0m Add Student" << endl;
        cout << "\033[31m[4]\033[0m Logout" << endl;

        cout << "Enter your choice: \033[32m";
        cin >> choice;
        cout << "\033[0m";

        utilsAdmin.delayAnimation(250);
        switch (choice)
        {
            case 1: if (manageStudentGrades() == 0) continue;
                break;
            case 2: if (manageStudentInformation() == 0) continue;
                break;
            case 3: if (addStudent() == 0) continue;
                break;
            case 4: utilsAdmin.logout(); 
                return true;
            default:
                cout << "Invalid choice, try again" << endl; 
                utilsAdmin.delayAnimation(250); 
                continue;
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

int Admin::addStudent()
{
    utilsAdmin.listInformationNeeded();
    utilsAdmin.delayAnimation(250);
    
    return 0;
}