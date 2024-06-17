#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using std::string;

//add student features here, then define feature in student.cpp
class Student
{
public:
    Student(const string& name);
    void studentMenu();
    void viewCOR();
    void viewGrade();
    bool logout();
private:
    string name;
};

#endif