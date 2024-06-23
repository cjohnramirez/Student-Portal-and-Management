#include "teacher.h"
#include "utils.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

Utils& utilsTeacher = Utils::getInstance();

bool Teacher::teacherMenu(string name)
{
    this->name = name;

    while (true)
    {
        cout << "\033[94m" << R"(  _____ _____    _    ____ _   _ _____ ____  
 |_   _| ____|  / \  / ___| | | | ____|  _ \
   | | |  _|   / _ \| |   | |_| |  _| | |_) |
   | | | |___ / ___ \ |___|  _  | |___|  _ < 
   |_| |_____/_/   \_\____|_| |_|_____|_| \_\
                                             )" << "\033[0m" << endl;
        cout << "Welcome, " << name << "!\n" << endl;
        cout << "\033[32m[1]\033[0m View Students" << endl;
        cout << "\033[31m[2]\033[0m Logout" << endl;

        cout << "Enter your choice: \033[32m";
        cin >> choice;
        cout << "\033[0m";

        utilsTeacher.delayAnimation(200);
        switch (choice)
        {
            case 1: if (viewStudents() == 0) continue;
                break;
            case 2: utilsTeacher.logout();
                return true;
            default:
                cout << "Invalid choice, try again" << endl;
                utilsTeacher.delayAnimation(250); 
                continue;
        }
    }

    return false;
}

int Teacher::viewStudents()
{
    if (utilsTeacher.teacherCourses(name) == 0) return 0;

    return 1;
}

