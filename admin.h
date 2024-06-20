#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include "person.h"
using std::string;

//add admin features
class Admin : public Person {
public:
    Admin (const string& name) : Person(name) {}; 
    bool adminMenu();
    int manageStudent();
    int manageTeacher();
private:
    int choice;
};

#endif