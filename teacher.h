#ifndef TEACHER_H
#define TEACHER_H
#include <string>
#include "person.h"
using std::string;

//add teacher features
class Teacher : public Person {
public:
    Teacher (const string& name) : Person(name) {};
    bool teacherMenu();
    int viewStudents();
private:
    int choice;
};

#endif