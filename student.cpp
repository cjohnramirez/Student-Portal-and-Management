#include "student.h"
#include <iostream>
using std::cout, std::cin, std::endl;

Student::Student(const string& name)
{
    this->name = name;
    this->isTrue = false;
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
            if (choice == 1){
                if (viewCOR() == 0) continue;
            }
            else if (choice == 2){
                if (viewGrade() == 0) continue;
            }
            else if (choice == 3){
                this->isTrue = true; break;
            }

        } else {
            cout << "Invalid choice, try again" << endl;
        }
    }
}

int Student::viewCOR()
{
    cout << "COR" << endl;
    returnButton();
    if (choice == 0) return 0;
    
    return 1;
}

int Student::viewGrade()
{
    cout << "Grades" << endl;
    returnButton();
    if (choice == 0) return 0;

    return 1;
}

int Student::returnButton(){
    cout << "[0] Back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    system("cls");
    return 1;
}

bool Student::logout()
{
    system("cls");
    return isTrue;
}

