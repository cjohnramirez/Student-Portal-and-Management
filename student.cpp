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

    int choice;
    bool runChoice = true;
    while (runChoice)
    {
        cout << "\033[94m" << R"(  ____ _____ _   _ ____  _____ _   _ _____ 
 / ___|_   _| | | |  _ \| ____| \ | |_   _|
 \___ \ | | | | | | | | |  _| |  \| | | |  
  ___) || | | |_| | |_| | |___| |\  | | |  
 |____/ |_|_ \___/|____/|_____|_| \_| |_|  
 |  _ \ / _ \|  _ \_   _|/ \  | |          
 | |_) | | | | |_) || | / _ \ | |          
 |  __/| |_| |  _ < | |/ ___ \| |___       
 |_|    \___/|_| \_\|_/_/   \_\_____|      
                                           )" << "\033[0m" << endl;
        cout << "Welcome, " << name << "!\n" << endl;
        cout << "\033[32m[1]\033[0m View Information" << endl;
        cout << "\033[32m[2]\033[0m View Grades" << endl;
        cout << "\033[31m[3]\033[0m Logout" << endl;

        cout << "Enter your choice: \033[32m";
        cin >> choice;
        cout << "\033[0m";

        utilsStudent.delayAnimation(200);
        switch(choice){
            case 1: if (viewInformation() == 0) continue;
                break;
            case 2: if (viewGrade() == 0) continue;
                break;
            case 3: utilsStudent.logout(); 
                return true;
            default:
                cout << "Invalid choice, try again" << endl; 
                utilsStudent.delayAnimation(250); 
                continue;
        }
    }

    return false;
}

int Student::viewInformation() //sub-menu, views COR in a file
{
    utilsStudent.studentInformation(name);

    utilsStudent.returnButton(choice);
    if (choice == 0) return 0;
    
    return 1;
}

int Student::viewGrade() //sub-menu, views grade in a file
{
    utilsStudent.studentGrades(name);

    utilsStudent.returnButton(choice);
    if (choice == 0) return 0;

    return 1;
}
