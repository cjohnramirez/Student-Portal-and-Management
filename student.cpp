#include "student.h"
#include "utils.h"
#include <iostream>
using std::cout, std::cin, std::endl;

Utils& utilsStudent = Utils::getInstance();

bool Student::studentMenu() //main menu of student class
{
    utilsStudent.delayAnimation();

    int choice;
    bool runChoice = true;
    while (runChoice)
    {
        cout << "Welcome, " << name << "!" << endl;
        cout << "[1] View COR" << endl;
        cout << "[2] View Grade" << endl;
        cout << "[3] Logout" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        utilsStudent.delayAnimation();
        switch(choice){
            case 1: if (viewCOR() == 0) continue;
                break;
            case 2: if (viewGrade() == 0) continue;
                break;
            case 3: utilsStudent.logout(); 
                return true;
            default:
                cout << "Invalid choice, try again" << endl; continue;
        }
    }

    return false;
}

int Student::viewCOR() //sub-menu, views COR in a file
{
    cout << "COR" << endl;

    utilsStudent.returnButton(choice);
    if (choice == 0) return 0;
    
    return 1;
}

int Student::viewGrade() //sub-menu, views grade in a file
{
    cout << "Grades" << endl;
    utilsStudent.studentInfo(name);

    utilsStudent.returnButton(choice);
    if (choice == 0) return 0;

    return 1;
}
