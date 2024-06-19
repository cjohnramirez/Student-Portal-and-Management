#ifndef ADMIN_H
#define ADMIN_H
#include <string>
using std::string;

//add admin features
class Admin{
    Admin (const string& name);
    bool adminMenu();
    int manageStudent();
    int manageTeacher();
private:
    string name;
    int choice;
};

#endif