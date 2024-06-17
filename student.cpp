#include "student.h"
#include <iostream>
using std::cout, std::cin, std::endl;

Student::Student(const string& name)
{
    this->name = name;
}

void Student::studentMenu()
{
    system("cls");

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
            if (choice == 1)
                viewCOR();
            else if (choice == 2)
                viewGrade();
            else if (choice == 3)
                logout();

            runChoice = false;
        } else {
            cout << "Invalid choice, try again" << endl;
        }
    }
}

void Student::viewCOR()
{

}

void Student::viewGrade()
{

}

bool Student::logout()
{
    system("cls");
    return true;
}
