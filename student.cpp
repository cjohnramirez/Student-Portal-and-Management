#include "student.h"
#include "utils.h"
#include <iostream>
#include <windows.h>
using std::cout, std::cin, std::endl;

Utils utils2;

Student::Student(const string& name) //constructor
{
    this->name = name;
}

int Student::studentMenu() //main menu of student class
{
    utils2.delayAnimation();

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

        if (choice == 1 || choice == 2 || choice == 3)
        {   
            if (choice == 1){
                if (viewCOR() == 0) continue;
            }
            else if (choice == 2){
                if (viewGrade() == 0) continue;
            }
            else if (choice == 3){
                utils2.logout(0); break;
            }

        } else {
            cout << "Invalid choice, try again" << endl;
        }
    }

    return 0;
}

int Student::viewCOR() //sub-menu, views COR in a file
{
    cout << "COR" << endl;
    utils2.returnButton(choice);
    if (choice == 0) return 0;
    
    return 1;
}

int Student::viewGrade() //sub-menu, views grade in a file
{
    cout << "Grades" << endl;
    utils2.returnButton(choice);
    if (choice == 0) return 0;

    return 1;
}
