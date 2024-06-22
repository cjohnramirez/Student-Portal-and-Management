#include "student.h"
#include "utils.h"
#include "login.h"
#include <iostream>
using std::cout, std::cin, std::endl;

Utils& utilsStudent = Utils::getInstance();
Login student;

bool Student::studentMenu(string name) //main menu of student class
{
    this->name = name;
    utilsStudent.delayAnimation(0.25);

    int choice;
    bool runChoice = true;
    while (runChoice)
    {
        cout << "Welcome, " << name << "!" << endl;
        cout << "[1] View Information" << endl;
        cout << "[2] View Grades" << endl;
        cout << "[3] Logout" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        utilsStudent.delayAnimation(0.25);
        switch(choice){
            case 1: if (viewInformation() == 0) continue;
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

int Student::viewInformation() //sub-menu, views COR in a file
{
    cout << "View Information" << endl;

    utilsStudent.studentInformation(name);

    utilsStudent.returnButton(choice);
    if (choice == 0) return 0;
    
    return 1;
}

int Student::viewGrade() //sub-menu, views grade in a file
{
    cout << "Grades" << endl;
    utilsStudent.studentGrades(name);

    utilsStudent.returnButton(choice);
    if (choice == 0) return 0;

    return 1;
}
