#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "person.h"
using std::string;

//add student features
class Student : public Person
{
public:
    Student(const string& name) : Person(name) {};
    bool studentMenu(); //finished
    int viewCOR();
    int viewGrade();
private:
    int choice;
};

#endif