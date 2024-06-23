#ifndef ADMIN_H
#define ADMIN_H
#include <string>
using std::string;

//add admin features
class Admin {
public:
    bool adminMenu(string name);
    int manageStudentGrades(); 
    int manageStudentInformation();
    int addStudent();
private:
    int choice;
    int shift;
};

#endif