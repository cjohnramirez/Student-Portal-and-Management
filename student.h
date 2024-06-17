#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using std::string;

//add student features here, then define feature in student.cpp
class Student
{
public:
    Student(const string& name);
    int studentMenu(); //finished
    int viewCOR();
    int viewGrade();
    bool logout(bool isTrue);
    int returnButton();
private:
    string name;
    int choice;
};

#endif